#include <array>
#include <string>

struct Node {
	// The problem specifies only lowercase English letters, so we can use an
	// array with a size of 26. From experimenting, this is slightly faster than
	// using a std::list (16ms vs 18ms), but with slightly higher memory usage
	// (50.5MB vs 33.6MB).
	// Note for this exercise raw pointers are used, but in production a safer
	// option should be considered, such as unique_ptr.
	std::array<Node *, 26> nodes{nullptr};
	bool isComplete = false;
};

class Trie {
public:
	Trie() {

	}

	void insert(const std::string &word) {
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

	bool search(const std::string &word) {
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

	bool startsWith(const std::string &prefix) {
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
