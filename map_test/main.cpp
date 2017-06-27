#include <string>
//#include <map>
#include <unordered_map>
#include <array>
#include <algorithm> //find
#include <iostream>

//std::map<const char *, std::string> mp;
std::unordered_map<const char *, std::string> mp;


void outside() {
    //std::cout << "Result4: " << mp[attrs[0]] << '\n';
    std::cout << "Result4: " << mp["title"] << '\n';
}

void set(const char *key, std::string value) {
    mp[key] = value;
}

enum class RssAttribute {
    title,
    description,
    link,
    category,
    copyright,
    language,
    lastBuildDate,
    managingEditor,
    pubDate,
    webMaster,
    generator
};

std::unordered_map<RssAttribute, std::string> mpx;

int main(int argc, char** argv) {
    const std::array<const char *, 11> attrs{
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
        "generator"};
    auto attrEnd = attrs.end();

    auto match = std::find(attrs.begin(), attrEnd, "title");

    if (match != attrEnd) {
        std::cout << "Found\n";
        //mp[*match] = "HEY HEY";
        set(*match, std::string("HEY HEY"));

        std::cout << "Result: " << mp[*match] << '\n';
        std::cout << "Result2: " << mp[attrs[0]] << '\n';
        std::cout << "Result3: " << mp["title"] << '\n';
        outside();
    } else {
        std::cout << "NOT Found\n";
    }

    return 0;
}

