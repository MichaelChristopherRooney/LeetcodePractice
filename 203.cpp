#include <iostream>
#include <list>

struct Node {
	// The problem specifies only lowercase English letters, so we can use an
	// array with a size of 26. From experimenting, this is slightly faster than
	// using a std::list (16ms vs 18ms), but with slightly higher memory usage
	// (50.5MB vs 33.6MB).
	std::array<Node *, 26> nodes{nullptr};
	bool isComplete = false;
};

class Trie {
public:
	Trie() {

	}

	void insert(std::string word) {
		auto cur = &m_Root;
		for(const auto originalC : word) {
			const auto c = originalC - 'a';
			if(cur->nodes[c] == nullptr) {
				cur->nodes[c] = new Node();
			}
			cur = cur->nodes[c];
		}
		cur->isComplete = true;
	}

	bool search(std::string word) {
		auto cur = &m_Root;
		for(const auto originalC : word) {
			const auto c = originalC - 'a';
			if(cur->nodes[c] == nullptr) {
				return false;
			}
			cur = cur->nodes[c];
		}
		return cur->isComplete;
	}

	bool startsWith(std::string prefix) {
		auto cur = &m_Root;
		for(const auto originalC : prefix) {
			const auto c = originalC - 'a';
			if(cur->nodes[c] == nullptr) {
				return false;
			}
			cur = cur->nodes[c];
		}
		return true;
	}

private:
	Node m_Root;
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
