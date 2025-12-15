
using namespace std;

class Node {
public:
    int numberOfMonsters;
    int numberOfKeys;
    int width;
    int height;
    int monstersDelay;

    Node *left;
    Node *right;

    Node(int monsters, int keys,  int h, int w, int delay) {
        numberOfMonsters = monsters;
        numberOfKeys = keys;
        width = w, height = h;
        monstersDelay = delay;
    }
};

class LevelSetting {
public:

    Node* currentLevel;

    LevelSetting() {
        currentLevel = nullptr;

        Node *root   = new Node(2, 2, 9, 17, 50);

        Node *Node1 = new Node(4, 3, 15, 27, 30);
        Node* Node1_1 = new Node(7, 8, 33, 55, 20);
        Node* Node1_2 = new Node(1, 2, 13, 23, 40);

        Node *Node2 = new Node(1, 1, 7, 13, 70);
        Node *Node2_1 = new Node(2, 4, 15, 25, 30);
        Node *Node2_2 = new Node(1, 1, 13, 25, 90);


        root->right = Node1;
        root->left = Node2;

        Node1->right = Node1_1;
        Node1->left = Node1_2;

        Node2->right = Node2_1;
        Node2->left = Node2_2;

        currentLevel = root;
    }
};

