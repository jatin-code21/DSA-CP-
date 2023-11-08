#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

struct comp
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

Node *makeNode(char ch, int freq, Node *l, Node *r)
{
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = l;
    node->right = r;

    return node;
}

void encode(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (!root) return;
    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(Node *root, int &index, string str)
{
    if (!root) return;
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;
    if (str[index] == '0')
    {
        decode(root->left, index, str);
    }
    else decode (root->right, index, str);
}

void buildHuffman(string s)
{
    unordered_map<char, int> mp;
    for (auto it: s) mp[it]++;

    priority_queue<Node*, vector<Node *>, comp> pq;

    //making the leaf node
    for (auto it: mp)
    {
        pq.push(makeNode(it.first, it.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        Node *l = pq.top(); pq.pop();
        Node *r = pq.top(); pq.pop();

        int sum = l->freq + r->freq;
        pq.push(makeNode('\0', sum, l, r));
    }

    Node *root = pq.top();
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);
    string str = "";
    cout << "Huffman code are: " << endl;
    for (auto it: huffmanCode)
    {
        cout << it.first << " " << it.second << "\n";
    }
    for (auto it: s)
    {
        str += huffmanCode[it];
    }
    cout << "Encode string is: " << str << "\n";
    int index = -1;
    while (index < (int)str.size() - 2)
    {
        decode(root, index, str);
    }
}

int main()
{
    string text = "Huffman coding is a data compression algorithm.";
    buildHuffman(text);
}