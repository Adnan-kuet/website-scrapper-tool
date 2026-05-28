#include "parser.hpp"
#include <gumbo.h>
#include <algorithm>

Parser::Parser(const std::string& html) : html_(html) {}

std::vector<Link> Parser::extractLinks() {
    GumboOutput* output = gumbo_parse(html_.c_str());
    std::vector<Link> links;

    std::function<void(GumboNode*)> traverse = [&](GumboNode* node) {
        if (node->type != GUMBO_NODE_ELEMENT) return;
        if (node->v.element.tag == GUMBO_TAG_A) {
            GumboAttribute* href = gumbo_get_attribute(&node->v.element.attributes, "href");
            if (href) {
                Link l;
                l.href = href->value;
                if (node->v.element.children.length > 0) {
                    GumboNode* textNode = static_cast<GumboNode*>(node->v.element.children.data[0]);
                    if (textNode->type == GUMBO_NODE_TEXT)
                        l.text = textNode->v.text.text;
                }
                links.push_back(l);
            }
        }
        GumboVector* children = &node->v.element.children;
        for (unsigned int i = 0; i < children->length; ++i)
            traverse(static_cast<GumboNode*>(children->data[i]));
    };

    traverse(output->root);
    gumbo_destroy_output(&kGumboDefaultOptions, output);
    return links;
}