#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <functional> //function
#include <algorithm> //find
#include <unordered_map>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>


namespace AcsFeedReader {

    class XMLNode {
    private:
        xmlNodePtr nptr;
    public:

        XMLNode(const xmlNodePtr n) : nptr(n) {
        }

        std::string getContent() {
            std::string data;

            xmlChar *key = xmlNodeListGetString(nptr->doc, nptr->xmlChildrenNode, 1);
            data = reinterpret_cast<char*> (key);
            xmlFree(key);

            return data;
        }

        //user-defined conversion operator

        operator bool() {
            return !isNull();
        }

        void iterateChildren(std::function<bool(XMLNode&) > func) {
            auto ele = getChildrenNode();

            while (ele) {
                if (!ele.isBlank()) {
                    if (!func(ele)) {
                        break;
                    }
                }
                ele = ele.getNext();
            }
        }

        bool isNull() const noexcept {
            return (nptr == nullptr);
        }

        bool isBlank() const noexcept {
            //http://www.xmlsoft.org/html/libxml-tree.html#xmlIsBlankNode
            return (xmlIsBlankNode(nptr) == 1);
        }

        std::string getName() const noexcept {
            return nptr ? std::string(reinterpret_cast<const char*> (nptr->name)) : std::string{};
        }

        XMLNode getChildrenNode() {
            return {nptr->xmlChildrenNode};
        }

        XMLNode getNext() {
            return {(nptr->next)};
        }


    };

    class XMLParser {
    public:

        XMLParser() {
        }

        XMLParser(const std::string file) {
            Parse(file);
        }

        void Parse(const std::string file) {
            doc = xmlParseFile(file.c_str());

            if (doc == NULL) {
                throw std::runtime_error("Document not parsed successfully");
            }
        }

        ~XMLParser() {
            if (doc) {
                xmlFreeDoc(doc);
            }
        }

        XMLNode getRootElement() const noexcept {
            return doc ? XMLNode{xmlDocGetRootElement(doc)} : XMLNode{nullptr};
        }

        xmlDocPtr getDocument() const noexcept {
            return doc ? doc : nullptr;
        }

        XMLNode findNode(const char *name) const noexcept {
            return findNode(std::string{name});
        }

        XMLNode findNode(const std::string name) const noexcept {
            return findNode(getRootElement(), name);
        }

        XMLNode findNode(XMLNode cur, const std::string name) const noexcept {
            auto ele = cur.getChildrenNode();

            while (ele) {
                if (!ele.isBlank() && ele.getName() == name) {
                    return ele;
                }

                ele = ele.getNext();
            }

            return XMLNode{nullptr};
        }

    private:
        xmlDocPtr doc = nullptr;
        xmlNodePtr cur = nullptr;
    };

    struct RssFeedImage {
        std::string url;
        std::string title;
        std::string link;
        std::string description;
        std::string width;
        std::string height;
    };

    struct RssFeedItem {
        std::string title;
        std::string description;
        std::string link;
        std::string category;
        std::string comments;
        std::string pubDate; //Possible change to some date format
    };

    class RssFeed {
    public:

        RssFeed(XMLNode channel) {
            auto func = [this](auto &node) {
                auto nodeType{node.getName()};
                auto attrEnd = RssFeed::attrs.end();
                auto i = std::find(RssFeed::attrs.begin(),attrEnd, nodeType);
                
                if (i != attrEnd) {
                    std::cout << "Attr:" << *i << " name:" << node.getName() << " Value:" << node.getContent() << '\n';
                }
                /*
                if (node.getName() == "title") {
                    this->title = node.getContent();
                }*/
                return true;
            };

            channel.iterateChildren(func);
        }  

    private:
        static const std::array<const char *, 11> attrs{
            "title",
            "description",
            "link",
            "category",
            "copyright",
            "language",
            "lastBuildDate",
            "managingEditor",
            "pubDate",
            "webMaster",
            "generator"
        };
        std::unordered_map<const char *, std::string> attrsValues;        
        RssFeedImage image;
        std::vector<RssFeedItem> items;
    };

    class FeedParser {
    private:
        XMLParser xmlParser;

        bool isRss() {
            return (xmlParser.getRootElement().getName() == "channel");
        }
    public:

        FeedParser(const std::string file) {
            xmlParser.Parse(file);

            if (isRss()) {
                RssFeed rFeed{xmlParser.getRootElement()};
            }

            /*
            auto channelNode = xmlParser.findNode("channel");

            if (!channelNode.isNull()) {
                auto titleNode = xmlParser.findNode(channelNode, "title");

                if (!titleNode.isNull()) {
                    //std::string data = xmlParser.getNodeContent(titleNode);
                    std::cout << "Title: " << titleNode.getNodeContent() << '\n';
                }
            }
             */
        }
    };

    class FeedReader {
    public:

        FeedReader(const std::string source) {
            if (is_http(source)) {
                //download the file
            }

            FeedParser fParser{source};
        }
    private:

        bool is_http(std::string data) const noexcept {
            return (data.compare(0, 4, "http") == 0);
        }


    };

    class AtomFeed {
    };
}

void
parseStory(xmlDocPtr doc, xmlNodePtr cur) {

    xmlChar *key;
    cur = cur->xmlChildrenNode;
    while (cur != NULL) {
        if ((xmlStrcmp(cur->name, (const xmlChar *) "item") == 0)) {

            xmlNodePtr curItem = cur->xmlChildrenNode;

            while (curItem != NULL) {
                if ((xmlStrcmp(curItem->name, (const xmlChar *) "title") == 0)) {
                    key = xmlNodeListGetString(doc, curItem->xmlChildrenNode, 1);
                    printf("title: %s\n", key);
                    xmlFree(key);
                }


                curItem = curItem->next;
            }


            //key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            //printf("keyword: %s\n", key);
            //xmlFree(key);
        }
        cur = cur->next;
    }
    return;
}

static void
parseDoc(char *docname) {

    xmlDocPtr doc;
    xmlNodePtr cur;

    doc = xmlParseFile(docname);

    if (doc == NULL) {
        fprintf(stderr, "Document not parsed successfully. \n");
        return;
    }

    cur = xmlDocGetRootElement(doc);

    if (cur == NULL) {
        fprintf(stderr, "empty document\n");
        xmlFreeDoc(doc);
        return;
    }
    /*
        if (xmlStrcmp(cur->name, (const xmlChar *) "story")) {
            std::cout << cur->name << '\n';
            fprintf(stderr, "document of the wrong type, root node != story");
            xmlFreeDoc(doc);
            return;
        }*/

    cur = cur->xmlChildrenNode;
    while (cur != NULL) {
        if (!xmlIsBlankNode(cur)) {
            std::cout << cur->name << '\n';
        }
        ///*
        if ((xmlStrcmp(cur->name, (const xmlChar *) "channel") == 0)) {
            parseStory(doc, cur);
        }
        //*/
        cur = cur->next;
    }

    xmlFreeDoc(doc);
    return;
}

int
main(int argc, char **argv) {
    std::string docname{"feeds/rss2.0.xml"};
    AcsFeedReader::XMLParser xmlParser{docname};
    auto channelNode = xmlParser.findNode("channel");

    AcsFeedReader::RssFeed rFeed{channelNode};

    //std::cout << "title:" << rFeed.getTitle() << '\n';



    /*
        auto channelNode = xmlParser.findNode("channel");


        if (channelNode) {
            auto titleNode = xmlParser.findNode(channelNode, "title");

            if (titleNode) {
        
                xmlChar *key = xmlNodeListGetString(xmlParser.getDocument(), titleNode->xmlChildrenNode, 1);
                printf("title: %s\n", key);
                xmlFree(key);
  

                std::cout << "Title: " << titleNode.getNodeContent() << '\n';
            } else {
                std::cout << "No title node\n";
            }
        } else {
            std::cout << "No channel node\n";
        }
     */



    //return );
}