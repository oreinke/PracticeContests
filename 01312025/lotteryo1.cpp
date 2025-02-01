#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////
// Fenwick Tree (BIT) for XOR flips //
//////////////////////////////////////
// We'll store an array fenwicksum[] where fenwicksum[i] indicates toggles.
// query(i) gives how many toggles (mod 2) affect index i.
struct Fenwick {
    int n;
    vector<int> fenwicksum;
    Fenwick(int n) : n(n), fenwicksum(n+1, 0) {}

    // Add 'val' to fenwicksum[pos] in a Fenwick tree sense (for XOR, val is 0 or 1).
    void update(int pos, int val) {
        for (; pos <= n; pos += pos & -pos) {
            fenwicksum[pos] ^= val; // XOR update
        }
    }
    // Query prefix XOR up to 'pos'
    int query(int pos) {
        int result = 0;
        for (; pos > 0; pos -= pos & -pos) {
            result ^= fenwicksum[pos];
        }
        return result;
    }
};

//////////////////////////////////////////////////
// Trie that stores ASCII children + sorted IDs //
//////////////////////////////////////////////////
struct Trie {
    static const int ALPHABET_SIZE = 128; // for ASCII or you can reduce if just 'a'..'z'
    struct Node {
        // pointers to children
        Node* child[ALPHABET_SIZE];
        // store all IDs of strings that pass this node
        vector<int> ids;  
        Node() {
            memset(child, 0, sizeof(child));
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    // Insert string s with ID 'id' into this trie
    void insert(const string &s, int id) {
        Node* cur = root;
        for (char c : s) {
            unsigned char uc = (unsigned char)c;
            if (!cur->child[uc]) {
                cur->child[uc] = new Node();
            }
            cur = cur->child[uc];
            cur->ids.push_back(id); 
        }
    }

    // Get the node corresponding to prefix 'p'. Return nullptr if not found.
    Node* getPrefixNode(const string &p) {
        Node* cur = root;
        for (char c : p) {
            unsigned char uc = (unsigned char)c;
            if (!cur->child[uc]) {
                return nullptr;
            }
            cur = cur->child[uc];
        }
        return cur;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "Lottery #" << tc << ":\n";

        // We'll maintain two tries: forward and backward
        Trie forwardTrie, backwardTrie;

        // Fenwicksum for up to n=10^5 insertions (or whatever max)
        // We'll build it after we read how many commands, or we can fix a large size.
        // We'll figure out the maximum possible insertions:
        int n; 
        cin >> n;

        // We don't know how many "command=1" we'll get, but let's assume worst case = n.
        // So let's just set Fenwicksum to size n. 
        Fenwick fenwicksum(n);

        // We'll track how many strings have been inserted so far
        int insertedCount = 0;

        while(n--){
            int command; 
            cin >> command;

            if(command == 1){
                // Insert a new name in normal orientation => forward trie
                // Also in reversed orientation => backward trie
                // Then increment insertedCount
                insertedCount++;
                string name;
                cin >> name;

                // Insert in forward trie
                forwardTrie.insert(name, insertedCount);

                // Reverse and insert in backward trie
                string revName = name;
                reverse(revName.begin(), revName.end());
                backwardTrie.insert(revName, insertedCount);
            }
            else if(command == 2){
                // Query how many currently have the prefix
                string prefix;
                cin >> prefix;

                // (1) forward side
                int result = 0;
                {
                    auto node = forwardTrie.getPrefixNode(prefix);
                    if(node){
                        // node->ids => all IDs that pass this prefix in forward orientation
                        // We only count those with orientation=0
                        for(int id : node->ids){
                            // orientation = fenwicksum.query(id) % 2
                            if((fenwicksum.query(id) % 2) == 0){
                                result++;
                            }
                        }
                    }
                }

                // (2) backward side
                {
                    auto node = backwardTrie.getPrefixNode(prefix);
                    if(node){
                        // node->ids => all IDs that pass this prefix in backward orientation
                        // We only count those with orientation=1
                        for(int id : node->ids){
                            // orientation = fenwicksum.query(id) % 2
                            if((fenwicksum.query(id) % 2) == 1){
                                result++;
                            }
                        }
                    }
                }

                cout << result << "\n";
            }
            else {
                // command == 3: Flip orientation for all so-far inserted
                // This is toggling IDs [1..insertedCount]
                if(insertedCount > 0){
                    fenwicksum.update(1, 1); 
                    fenwicksum.update(insertedCount+1, 1); 
                }
            }
        }
        cout << endl;
    }
    return 0;
}
