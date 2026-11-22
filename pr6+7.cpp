#include <iostream>
#include <vector>

template <typename T>
struct Node{
	T val;
	Node<T> * prev;
	Node<T> * next;

	Node(const T &s) {
        val = s;
        prev = nullptr;
        next = nullptr;
    }
};

template <typename T>
struct List{
	Node<T> * start;
	int count;

	List(){ start = nullptr; count = 0;}
	List(const T &s){ start = new Node<T>(s); start->next = start; start->prev = start; count = 1;}
	~List() {
        if (!start) return;
		Node<T>* current = start->next;
		while (current != start){
			Node<T>* next_node = current->next;
			delete current;
			current = next_node;
		}
        delete start;
		start = nullptr;
	}
	void Add(const T &s, Node<T>* node){
        if (node == nullptr) return; 
		Node<T> * new_node = new Node<T>(s);

		if (count == 0){
			new_node->next = new_node;
			new_node->prev = new_node;
			start = new_node;
		}
		else {
			Node<T> * next_node = node->next;
			new_node->next = next_node;
			new_node->prev = node;

			node->next = new_node;
			next_node->prev = new_node;
		
		}
		count++;
	}

	void Remove(Node<T>*node){
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

	void Swap(Node<T>* n1, Node<T> * n2){
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
				Node<T> * u1= n1->next;
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
        Node<T> * cur = start;
        do {
            std::cout << cur->val << "\t";
            cur = cur->next;
        } while (cur != start);
        std::cout << "\n";
	}
void BubbleSort(){
    if (count < 2) return;

    bool swapped = true;
    Node<T>* end = start;
    while(swapped){
        swapped = false;
        Node<T>* current = start;
        do {
            Node<T>* next = current->next;
            if(next == start) break;
            if (current->val > next->val){
                Swap(current, next);
                swapped = true;
            }
            current = current->next;
        } while(current!= end);
        end = end->prev;
    }
}
void BubbleSort2(Node<T>* first, Node<T>* end){
    if (first->next==end) return;
    Node<T>* max_node = first;
    Node<T>* cur = first->next;
    while (true){
        if (max_node->val < cur->val) {
            max_node = cur;
        }
        cur = cur->next;
    if (cur == end->next) break;
    }

    if (max_node == end) BubbleSort2(first, end->prev);
    else {
        Node<T>* prev_node = end->prev;
        Node<T>* new_first = (max_node == first) ? end : first; 
        Swap(max_node, end);
        if (prev_node == max_node) BubbleSort2(first, end);
        else BubbleSort2(new_first, prev_node);
    }
}
};

int main(){
    // std::vector<int> s = {2, 3, 1, 53, 4, 1, 5, 3};
    std::vector<int> s = { 4, 3, -3, 1, 5, 10, 34, 1};
    
    List<decltype(s)::value_type> l(s[0]);
    for (int i = s.size()-1; i>0; i--){
        l.Add(s[i], l.start);
    }
	
	// l.BubbleSort();
    l.BubbleSort2(l.start, l.start->prev);
    //l.Print();
	//
    //l.Swap(l.start->next, l.start->next->next);
    //l.Print();
	//
    //l.Remove(l.start);
    l.Print();

    return 0;
}
