/*
Title: Write a c++ program to implement Huffman coding text compression algorithm. 
Build the huffman Tree using characters and their frequencies input from user. 
Encode a given string by using codes generated from huffman tree and decode the bit sequence 
entered by the user. 
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// Huffman tree node
struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;

    Node(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = nullptr;
        right = nullptr;
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

// Builds the Huffman tree
Node* buildHuffmanTree(const unordered_map<char, int>& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : frequencies) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Combine nodes until there is only one node left (the root of the Huffman tree)
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    return pq.top();
}

// Traverse the Huffman tree and build the code table
void buildCodeTable(Node* root, const string& code, unordered_map<char, string>& codeTable) {
    if (root == nullptr)
        return;

    // Leaf node, add the character and its code to the code table
    if (!root->left && !root->right) {
        codeTable[root->data] = code;
    }

    // Traverse left and right subtrees
    buildCodeTable(root->left, code + "0", codeTable);
    buildCodeTable(root->right, code + "1", codeTable);
}

// Encode a given string using the code table
string encode(const string& text, const unordered_map<char, string>& codeTable) {
    string encodedText;
    for (char c : text) {
        encodedText += codeTable.at(c);
    }
    return encodedText;
}

// Decode a given bit sequence using the Huffman tree
string decode(const string& bitSequence, Node* root) {
    string decodedText;
    Node* current = root;
    for (char bit : bitSequence) {
        if (bit == '0') {
            current = current->left;
        } else if (bit == '1') {
            current = current->right;
        }

        // Leaf node, append the character to the decoded text
        if (!current->left && !current->right) {
            decodedText += current->data;
            current = root;
        }
    }
    return decodedText;
}

int main() {
    string text;
    cout << "Enter a text to compress: ";
    getline(cin, text);

    // Calculate character frequencies
    unordered_map<char, int> frequencies;
    for (char c : text) {
        frequencies[c]++;
    }

    // Build the Huffman tree
    Node* root = buildHuffmanTree(frequencies);

    // Build the code table
    unordered_map<char, string> codeTable;
    buildCodeTable(root, "", codeTable);

    // Encode the text
    string encodedText = encode(text, codeTable);

    cout << "Encoded text: " << encodedText << endl;

    // Decode the bit sequence
    cout << "Enter the bit sequence to decode: ";
    string bitSequence;
    cin >> bitSequence;

    string decodedText = decode(bitSequence, root);
    cout << "Decoded text: " << decodedText << endl;

    // Clean up memory
    delete root;

    return 0;
}
