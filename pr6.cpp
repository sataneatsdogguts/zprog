#include <iostream>
#include <string>
#include <vector>

struct Node{
	std::string val;
	Node * prev;
	Node * next;

	Node(std::string &s) {
        val = s;
        prev = nullptr;
        next = nullptr;
    }
};

struct List{
	Node * start;
	int count;

	List(){ start = nullptr; count = 0;}
	List(std::string &s){ start = new Node(s); start->next = start; start->prev = start; count = 1;}
	~List() {
        if (!start) return;
		Node* current = start->next;
		while (current != start){
			Node* next_node = current->next;
			delete current;
			current = next_node;
		}
        delete start;
		start = nullptr;
	}
	void Add(std::string &s, Node* node){
        if (node == nullptr) return; 
		Node * new_node = new Node(s);

		if (count == 0){
			new_node->next = new_node;
			new_node->prev = new_node;
			start = new_node;
		}
		else {
			Node * next_node = node->next;
			new_node->next = next_node;
			new_node->prev = node;

			node->next = new_node;
			next_node->prev = new_node;
		
		}
		count++;
	}

	void Remove(Node*node){
        if (node == nullptr) return; 
        else if (count == 1){
			start = nullptr;
		}
		else {
			node->next->prev = node->prev;
			node->prev->next = node->next;
            if (node == start){
                start = node->next;
            }
		}
		delete node;
		count--;
	}

	void Swap(Node* n1, Node * n2){
        if (n1== nullptr || n2 == nullptr) return; 
		if (count == 2){
			start = start->next;
		}
		else{
			if (n1->next==n2){
				n2->next->prev = n1;
				n1->prev->next = n2;
				n1->next = n2->next;
				n2->prev = n1->prev;
				n1->prev = n2;
				n2->next = n1;
			}
			else if (n1->prev == n2){
				n2->prev->next = n1;
				n1->next->prev = n2;
				n1->prev = n2->prev;
				n2->next = n1->next;
				n1->next = n2;
				n2->prev = n1;

			}
			else{
				n1->prev->next = n2;
				n1->next->prev = n2;
				n2->prev->next = n1;
				n2->next->prev = n1;
				Node * u1= n1->next;
				n1->next=n2->next;
				n2->next=u1;
				u1 = n1->prev;
				n1->prev=n2->prev;
				n2->prev=u1;

			}
			if (start == n1){
				start = n2;
			}
			else if (start == n2){
				start = n1;
			}
			
		}
	}
    void Print(){
        if (!start) {std::cout << "don't try to look into the void..." << "\n"; return;}
        Node * cur = start;
        do {
            std::cout << cur->val << "\t";
            cur = cur->next;
        } while (cur != start);
        std::cout << "\n";
    }
};

int main(){
    std::vector<std::string> s = {"sudo", "rm", "-rf", "--no-preserve-root", "/", "=)"};
    
    List l(s[0]);
    for (int i = s.size()-1; i>0; i--){
        l.Add(s[i], l.start);
    }
    l.Print();

    l.Swap(l.start->next, l.start->next->next);
    l.Print();

    l.Remove(l.start);
    l.Print();

    return 0;
}
