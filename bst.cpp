#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
	int data;
	node* left;
	node* right;

	node(int d){
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};
node* insertbst(node* root,int d){
	if(root==NULL){
		root=new node(d);
		return root;
	}
	if(root->data<d){
		root->right=insertbst(root->right,d);
	}
	else{
		root->left=insertbst(root->left,d);	
	}
	return root;
}
void inputbst(node* &root){
//
	cout<<"enter the element:"<<endl;
	int d;
	cin>>d;
	while(d != -1){
		root=insertbst(root,d);
		cin>>d;
	}
	
}
void levelorder(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp=q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty())
			q.push(NULL);
		}
		else{
			cout<<temp->data<<"  ";
			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right!=NULL){
			q.push(temp->right);}
			
		}
	}
}
void inorder(node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<"  ";
	inorder(root->right);
}
void preorder(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<"  ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(node* root){
	if(root==NULL){
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<"  ";
}
bool searchinbstrec(node* root,int key){
	if(root==NULL){
		return false;
	}
	if(root->data==key){
		return true;
	}
	if(key>root->data){
		searchinbstrec(root->right,key);
	}
	else{
		searchinbstrec(root->left,key);
	}
}
bool searchinbstiter(node* root,int key){
	while(root!=NULL){
		if(root->data==key){
		return true;
	}
	else if(key>root->data){
		root=root->right;
	}
	else{
		root=root->left;
	}
	}
	return false;
}	
node* maxi(node* root){
	if(root->right==NULL){
		return root;
	}
	maxi(root->right);
}
node* mini(node* root){
	if(root->left==NULL){
		return root;
	}
	mini(root->left);
}
node* miniiter(node* root){
//	node* temp;
	while(root->left!=NULL){
		root=root->left;
	}
	return root;
}
node* maxiiter(node* root){
//	node* temp;
	while(root->right!=NULL){
		root=root->right;
	}
	return root;
}
node* deletefrombst(node* &root,int key){
	if(root==NULL){
		return root;
	}
	if(root->data==key){
		if(root->left==NULL && root->right==NULL){//no child
			delete root;
			return NULL;
		}
		if(root->left==NULL && root->right!=NULL){
		//one child
		node* temp=root->right;
		delete root;
		return temp;
	}
	if(root->left!=NULL && root->right==NULL){
		//one child
		node* temp=root->left;
		delete root;
		return temp;
	}
	if(root->left!=NULL && root->right!=NULL){
		//one child
		int min=mini(root->right)->data;
		root->data=min;
		root->right=deletefrombst(root->right,min);
		return root;
	}}
	else if(root->data>key){
		root->left=deletefrombst(root->left,key);
		return root;
	}
	else{
		root->right=deletefrombst(root->right,key);
		return root;
	}
}
int main(){
	node* root=NULL;
	inputbst(root);
	levelorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	if(searchinbstiter(root,188)){
		cout<<"18 IS PRESENT"<<endl;
	}
	else{
		cout<<"188 IS NOT PRESENT"<<endl;
	}
	if(searchinbstrec(root,29)){
		cout<<"29 IS PRESENT"<<endl;
	}
	else{
		cout<<"29 IS NOT PRESENT"<<endl;
	}
	cout<<"MAX ELE:"<<maxi(root)->data<<endl;
	cout<<"MIN ELE:"<<mini(root)->data<<endl;
	cout<<"MIN ELE:"<<miniiter(root)->data<<endl;
	cout<<"MAX ELE:"<<maxiiter(root)->data<<endl;
	//50 20 70 10 30 90 110 -1
	//DELETION
	root=deletefrombst(root,30);
	levelorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
}
