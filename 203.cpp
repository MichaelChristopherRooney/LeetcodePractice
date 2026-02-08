#include <iostream>
#include <list>

struct Element {
	std::list<Element> subElements;
	char c;
	bool complete = false;
};

class Trie {
public:
	Trie() {

	}

	void insert(std::string word) {
		Element *cur = &m_RootElements;
		for(const auto c : word) {
			auto match = std::find_if(cur->subElements.begin(), cur->subElements.end(), [c](const Element &e) {
				return e.c == c;
			});
			if(match == cur->subElements.end()) {
				cur = &cur->subElements.emplace_back(Element {
					.subElements = std::list<Element>(),
					.c = c,
					.complete = false
				});
			} else {
				cur = &(*match);
			}
		}
		cur->complete = true;
	}

	bool search(std::string word) {
		Element *cur = &m_RootElements;
		for(const auto c : word) {
			auto match = std::find_if(cur->subElements.begin(), cur->subElements.end(), [c](const Element &e) {
				return e.c == c;
			});
			if(match == cur->subElements.end()) {
				return false;
			}
			cur = &(*match);
		}
		return cur->complete;
	}

	bool startsWith(std::string prefix) {
		Element *cur = &m_RootElements;
		for(const auto c : prefix) {
			auto match = std::find_if(cur->subElements.begin(), cur->subElements.end(), [c](const Element &e) {
				return e.c == c;
			});
			if(match == cur->subElements.end()) {
				return false;
			}
			cur = &(*match);
		}
		return true;
	}

private:
	Element m_RootElements;
};


int main() {
	std::cout << "Hello, World!" << std::endl;
	Trie* obj = new Trie();
	obj->insert("apple");
	const auto apple = obj->search("apple");
	const auto appSearch = obj->search("app");
	const auto appStartsWith = obj->startsWith("app");
	return 0;
}
