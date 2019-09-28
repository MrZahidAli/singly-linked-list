#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
};
class linkList{
	private:
		node *head, *tail;
	public:
		linkList(){
			head = NULL;
			tail = NULL;
		}
		void creatList(int value){
			node *temp = new node;
			temp -> data = value;
			temp -> next = NULL;
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail -> next = temp;
				tail = temp;
			}
			
		}
		void printList(){
			node *temp = new node;
			temp = head;
			while(temp != NULL){
				cout << temp -> data << "\t";
				temp = temp -> next;
			}
		}
		void search(int value){
			node *temp = new node;
			temp = head;
			bool find;
			while(temp != NULL){
				if(temp -> data == value){
					cout << temp -> data;
					find = true;
					break;
				}
				else{
					temp = temp -> next;
					find = false;
				}
			}
			if(find == false){
					cout << "not found";
			}
		}
		void removeElement(int remValue) {
		if(head == NULL){cout<<"NULL";}
		else{
    		node *prev = head;
    		node *current = head->next;
    		while(current != NULL) {
        		if(current -> data == remValue) { 
            		break;
        		}
        		else {
           			prev = current; 
            		current = current->next;
        		}
    		}
    		if(current == NULL) {
    			if(head -> data == remValue)
    			{
	        		cout << "Head Deleted: " <<"\t";
	        		head = head -> next;
	        	}
	        	else{
	        		cout << "not found" << "\n";
				}
    		} else {
        		cout << "Deleted: " << "\n";
        		prev->next = current->next;
        		delete current;
    		}
    	}
		}
		void sortedList(){
			node *prev = head;
			while(prev != NULL){
				node *current = head;
				while(current != NULL){				
					if(prev -> data < current -> data){
						prev -> data = prev -> data + current -> data;
						current -> data = prev -> data - current -> data;
						prev -> data = prev -> data - current -> data;										
					}
					current = current -> next;					
				}
				prev = prev -> next;				
									
			}
		}
};
int main(){
	linkList a;
	a.creatList(1);
	a.creatList(3);
	a.creatList(7);
	a.creatList(6);
	a.printList();
	a.removeElement(6);
	a.printList();
//	a.search(3);
//	a.sortedList();
//	cout<<"sorted linked list"<<endl;
//	a.printList();
	return 0;
}
