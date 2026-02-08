#include <iostream>

struct Element {
	std::array<std::unique_ptr<Element>, 256> subElements;
	bool complete;
};

class Trie {
public:
	Trie() {

	}

	void insert(std::string word) {
		Element *cur = &m_RootElements;
		for(const auto c : word) {
			if(cur->subElements[c] == nullptr) {
				cur->subElements[c] = std::make_unique<Element>();
			}
			cur = cur->subElements[c].get();
		}
		cur->complete = true;
	}

	bool search(std::string word) {
		Element *cur = &m_RootElements;
		for(const auto c : word) {
			if(cur->subElements[c] == nullptr) {
				return false;
			}
			cur = cur->subElements[c].get();
		}
		return cur->complete;
	}

	bool startsWith(std::string prefix) {
		Element *cur = &m_RootElements;
		for(const auto c : prefix) {
			if(cur->subElements[c] == nullptr) {
				return false;
			}
			cur = cur->subElements[c].get();
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
