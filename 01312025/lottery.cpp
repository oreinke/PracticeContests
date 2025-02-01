#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////
// Trie that stores ASCII children + IDs  //
////////////////////////////////////////////
struct Trie {
    static const int ALPHABET_SIZE = 128;  // works for ASCII
    struct Node {
        Node* child[ALPHABET_SIZE];
        // The IDs of the strings that pass through this node.
        vector<int> ids;
        Node() {
            memset(child, 0, sizeof(child));
        }
    };

    Node* root;
    Trie() { 
        root = new Node(); 
    }

    // Insert string s with identifier 'id' into the trie.
    void insert(const string &s, int id) {
        Node* cur = root;
        for (char c : s) {
            unsigned char uc = static_cast<unsigned char>(c);
            if (!cur->child[uc])
                cur->child[uc] = new Node();
            cur = cur->child[uc];
            cur->ids.push_back(id);
        }
    }

    // Return the node corresponding to prefix p, or nullptr if not found.
    Node* getPrefixNode(const string &p) {
        Node* cur = root;
        for (char c : p) {
            unsigned char uc = static_cast<unsigned char>(c);
            if (!cur->child[uc])
                return nullptr;
            cur = cur->child[uc];
        }
        return cur;
    }
};

////////////////////////////////////////////
// Main program using a standard array    //
// to track the effective orientation     //
////////////////////////////////////////////
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    for (int tc = 1; tc <= t; tc++){
        cout << "Lottery #" << tc << ":\n";

        Trie forwardTrie, backwardTrie;

        // Read the number of commands.
        int n;
        cin >> n;

        // insertedCount tracks the number of strings inserted so far.
        int insertedCount = 0;
        // We'll allocate an array (vector) for storing the flip base for each inserted string.
        // We use n+1 because at most n commands are insertions.
        vector<int> base(n+1, 0);
        // globalFlip tracks the overall flip state.
        int globalFlip = 0;

        while(n--){
            int command;
            cin >> command;

            if(command == 1){
                // Insert a new string.
                insertedCount++;
                string name;
                cin >> name;
                // Insert in normal order (forward trie).
                forwardTrie.insert(name, insertedCount);

                // Insert in reversed order (backward trie).
                string revName = name;
                reverse(revName.begin(), revName.end());
                backwardTrie.insert(revName, insertedCount);

                // Record the current global flip state for this string.
                // This “base” value will later let us compute the effective orientation.
                base[insertedCount] = globalFlip;
            }
            else if(command == 2){
                // Query: count strings with the given prefix.
                string prefix;
                cin >> prefix;
                int result = 0;

                // Check the forward trie.
                if (auto node = forwardTrie.getPrefixNode(prefix)) {
                    // For the forward trie we count strings whose effective orientation is 0.
                    for (int id : node->ids) {
                        if ((globalFlip ^ base[id]) == 0)
                            result++;
                    }
                }

                // Check the backward trie.
                if (auto node = backwardTrie.getPrefixNode(prefix)) {
                    // For the backward trie we count strings whose effective orientation is 1.
                    for (int id : node->ids) {
                        if ((globalFlip ^ base[id]) == 1)
                            result++;
                    }
                }

                cout << result << "\n";
            }
            else {
                // Command 3: Flip orientation for all inserted strings.
                // Instead of updating an array for every string,
                // we simply toggle the global flip.
                globalFlip ^= 1;
            }
        }
        cout << "\n";
    }
    return 0;
}
