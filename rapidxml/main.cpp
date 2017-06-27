#include <iostream>
#include <string>
#include "rapidxml-1.13/rapidxml_utils.hpp"

int main(int argc, char** argv) {
    //rapidxml::file<> xmlFile("feeds/rss2.0.xml"); // Default template is char
    rapidxml::file<> xmlFile("feeds/atom1.0.xml"); // Default template is char
    rapidxml::xml_document<> doc;
    doc.parse<0>(xmlFile.data());


    rapidxml::xml_node<> *node = doc.first_node();
    std::string rss = "rss";
    std::string atom = "feed";

    if (rss.compare(node->name()) == 0) {
        std::cout << "RSS FEED!\n";
        node = node->first_node("channel");
    } else if (atom.compare(node->name()) == 0) {
        std::cout << "ATOM FEED!\n";
    }


    //cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
    //std::cout << "Name of my first node is: " << node->name() << "\n";

    //int c = 0;
    for (rapidxml::xml_node<> *child = node->first_node(); child != NULL; child = child->next_sibling()) {
        std::cout << "Name: " << child->name() << "\n";
    }

    /*
        if (node->value()) {
            std::cout << "Node foobar has value " << node->value() << "\n";
        }

        for (rapidxml::xml_attribute<> *attr = node->first_attribute(); attr; attr = attr->next_attribute()) {
            std::cout << "Node foobar has attribute " << attr->name() << " ";
            std::cout << "with value " << attr->value() << "\n";
        }
     */

    return 0;
}

