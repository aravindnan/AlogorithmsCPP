#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include<map>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


// -------Stack----------
int stack[10],stackTop=-1,stackMax=10;
void stackPush(){
    if(stackTop== stackMax-1){
        cout<<"Stack is Full";
        getch();
        return;
    }
    else{
        cout<<"Enter Data To PUSH\n";
        cin>>stack[++stackTop];
    }
}
void stackPop(){
    if(stackTop==-1){
        cout<<"Stack is empty";
        getch();
        return;
    }
    cout<<"The deleted element is "<<stack[stackTop--]<<"\n";

}
void stackDisplay(){
    if(stackTop==-1){
        cout<<"Stack is Empty\n";
        getch();
        return;
    }
    else{
        cout<<"STACK--[\t";
        for (int i = 0; i <=stackTop; i++)
        {cout<<stack[i]<<"\t";} 
        cout<<"]";

    }
}


//-------Queue-----------
int queue[10],queueFront=-1,queueRear=-1,queueMax=10;
void queueInsert(){
    if(queueRear==queueMax-1){
        cout<<"\nQueue is Full\n";
        getch();
        return;
    }
    else{
        if(queueFront==-1){
            queueFront=0;
        }
        cout<<"\nEnter data to Insert\n";
        cin>>queue[++queueRear];
    }
}
void queueDelete()
{
    if(queueFront==-1||queueFront>queueRear){
        cout<<"\n Queue is Empty\n";
        getch();
        return;
    }
    else{
        cout<<"\nThe Deleted Element is "<<queue[queueFront++];
    }


}
void queueDisplay(){

    if (queueFront==-1)
    {
        cout<<"Queue is Empty";
        getch();
        return;
    }
    else{
        cout<<"QUEUE--[\t";
        for (int i = queueFront; i <=queueRear; i++)
        {
           cout<<queue[i]<<"\t"; 
        }
        cout<<"]";
        
    }
    


}

//------Circular Queue---
int Cqueue[5],CqueueFront=-1,CqueueRear=-1,CqueueMax=5;
void CqueueInsert(){
    if((CqueueFront==0 && CqueueRear==CqueueMax-1) || (CqueueFront==CqueueRear+1)){
        cout<<"\nCircular Queue is FULL\n";
        getch();
        return;
    }
    else{
        if(CqueueFront==-1){
            CqueueFront=CqueueRear=0;
        }
        else{
            if(CqueueRear==CqueueMax-1){
                CqueueRear=0;
            }
            else{
                CqueueRear++;
            }

        }
        cout<<"\nEnter Data to be Inserted\n";
        cin>>Cqueue[CqueueRear];

    }
    
}
void CqueueDisplay()
{
    if(CqueueFront==-1){
        cout<<"The Circular Queue is EMPTY";
        getch();
        return;
    }
    else{
        cout<<"CIRCULAR QUEUE--[\t";
        if(CqueueFront<=CqueueRear){
            for(int i=CqueueFront;i<=CqueueRear;i++){
                cout<<Cqueue[i]<<"\t";
            }
        }
        else{
            for(int i=0;i<=CqueueRear;i++){
                cout<<Cqueue[i]<<"\t";
            }
            for(int i=CqueueFront;i<=CqueueMax-1;i++){
                cout<<Cqueue[i]<<"\t";
            }
        }
        cout<<"]";


    }

}
void CqueueDelete(){
    if(CqueueFront==-1){
        cout<<"The Circular Queue is EMPTY";
        getch();
        return;
    }
    else{
        cout<<"The deleted Element is "<<Cqueue[CqueueFront];
        if(CqueueFront==CqueueRear)
        {
            CqueueFront=-1;
            CqueueRear=-1;
        }
        else{
            if(CqueueFront==CqueueMax-1){
                CqueueFront=0;
            }
            else{
                CqueueFront++;
            }
        }
    }

}

//------Linear Search----
int lsearchList[10],lsearchlen,lsearchdata,lsearchflag=0;
void linearSearch(){
    cout<<"\nEnter the Length of List\n";
    cin>>lsearchlen;
    cout<<"\n Enter "<<lsearchlen<<" Eleements \n";
    for(int i=0 ; i<=lsearchlen-1;i++){
        cin>>lsearchList[i];
    }
    cout<<"\nEnter the Data To be Searched\n";
    cin>>lsearchdata;
    for(int i=0;i<=lsearchlen-1;i++){
        if(lsearchList[i]==lsearchdata){
            cout<<"The Searched Element is at Postition \" "<<i+1<<"\"";
            lsearchflag=1;
            break;
        }
    }
    if(lsearchflag==0){
        cout<<"Element not Present in List (Press Enter to Continue)";
        getch();
    }

}


//------Binary Search---
int bsearchList[10],bsearchMid,bsearchFirst,bsearchLast,bsearchlen,bsearchdata,bsearchflag=0;
void binarySearch(){
    cout<<"\nEnter the Length of List\n";
    cin>>bsearchlen;
    cout<<"\n Enter "<<bsearchlen<<" Eleements \n";
    for(int i=0 ; i<=bsearchlen-1;i++){
        cin>>bsearchList[i];
    }
    cout<<"\nEnter the Data To be Searched\n";
    cin>>bsearchdata;

    bsearchFirst=0;
    bsearchLast=bsearchlen-1;

    while(bsearchFirst<bsearchLast){
        bsearchMid=(bsearchFirst+bsearchLast)/2;

        if(bsearchdata>bsearchList[bsearchMid]){
            bsearchFirst=bsearchMid+1;
        }
        else if(bsearchdata<bsearchList[bsearchMid]){
            bsearchLast=bsearchMid-1;
        }
        else if (bsearchdata==bsearchList[bsearchMid]){
            cout<<"\nSearched Data is Present at Position \""<<bsearchMid+1<<"\"\n";
            bsearchflag=1;
            return;
        }
        else
            break;
        
    }
    if(bsearchflag==0)
    cout<<"Element is Not Present in List(Press Enter To Continue)";
    getch();

}


// -----Bubble Sort----
int bsortList[10],bsortTemp,bsortlen;
void bubbleSort(){
    cout<<"\nEnter the Length of List\n";
    cin>>bsortlen;
    cout<<"\n Enter "<<bsortlen<<" Eleements \n";
    for(int i=0 ; i<=bsortlen-1;i++){
        cin>>bsortList[i];
    }

    for(int i=0;i<bsortlen;i++){
        for(int j=0;j<bsortlen-i-1;j++){
            if(bsortList[j]>bsortList[j+1]){
                bsortTemp=bsortList[j];
                bsortList[j]=bsortList[j+1];
                bsortList[j+1]=bsortTemp;
            }
        }
    }

    cout<<"\nThe Sorted List is --[\t";
    for (int i = 0; i < bsortlen; i++)
    {
       cout<<bsortList[i]<<"\t";
    }
    cout<<"]";
}


// ---Selection Sort---
int selsortList[10],selsortSmall,selsortTemp,selsortlen;
void selectionSort(){
    cout<<"\nEnter the Length of List\n";
    cin>>selsortlen;
    cout<<"\n Enter "<<selsortlen<<" Elements \n";
    for(int i=0 ; i<=selsortlen-1;i++){
        cin>>selsortList[i];
    }

    for(int i=0 ;i<selsortlen-1;i++){
        selsortSmall=i;
        for(int j=i+1;j<selsortlen;j++){
            if(selsortList[j]<selsortList[selsortSmall]){
                selsortSmall=j;
            }
        }
        selsortTemp=selsortList[i];
        selsortList[i]=selsortList[selsortSmall];
        selsortList[selsortSmall]=selsortTemp;
    }

    cout<<"The Sorted List is --[\t";
    for(int i=0;i<selsortlen;i++){
        cout<<selsortList[i]<<"\t";
    }
    cout<<"]";

}


// --Insertion Sort---
int insortList[10],insortlen,insortKey;
void insertionSort(){
    cout<<"\nEnter the Length of List\n";
    cin>>insortlen;
    cout<<"\n Enter "<<insortlen<<" Eleements \n";
    for(int i=0 ; i<=insortlen-1;i++){
        cin>>insortList[i];
    }

    for(int i=0;i<insortlen;i++){
        insortKey=insortList[i];
        int j = i-1;
        while(j>=0 && insortList[j]>insortKey){
            insortList[j+1]=insortList[j];
            j--;
        }
        insortList[j+1]=insortKey;
    }

    cout<<"The Sorted List is --[\t";
    for(int i=0;i<insortlen;i++){
        cout<<insortList[i]<<"\t";
    }
    cout<<"]";

}



// --Singly Linked list--
struct sll
{
   int info;
   struct sll *right; 
}*slltemp,*sllprev,*sllnewptr,*sllnext,*slllast,*sllfirst;
int sllCreate(){
    char ch;
    while(1){
        sllnewptr= (struct sll*)malloc(sizeof(struct sll));
        cout<<"\nEnter Data\n";
        cin>>sllnewptr->info;
        sllnewptr->right=NULL;
        if(sllfirst==NULL){
            sllfirst=slltemp=sllnewptr;
        }
        else{
            slltemp->right=sllnewptr;
            slltemp=slltemp->right;
        }

        slltemp=sllfirst;
        while(slltemp->right!=NULL){
             slltemp=slltemp->right;
             slllast=slltemp;
        }
        cout<<"\nWant to add More elements?(y/n)\n";
        ch=getch();
        if(ch=='n'||ch=='N')
        return 0;
    }
}
void sllDisplayForward(){

    if(sllfirst==NULL){
        cout<<"\nThe List is Empty\n";
        return;
    }
    slltemp=sllfirst;

    cout<<" Forward Display--[\t";
    while (slltemp!=NULL)
    {
        cout<<slltemp->info<<"\t";
        slltemp=slltemp->right;
    }
    cout<<"]";  
}
void sllInsertBegining(){

    sllnewptr=(struct sll*)malloc(sizeof(struct sll));
    cout<<"\nEnter Data\n";
    cin>>sllnewptr->info;
    sllnewptr->right=sllfirst;
    sllfirst=sllnewptr;

}
void sllInsertEnd(){
    sllnewptr=(struct sll*)malloc(sizeof(struct sll));
    cout<<"\nEnter Data\n";
    cin>>sllnewptr->info;
    slltemp=sllfirst;
        while(slltemp->right!=NULL){
             slltemp=slltemp->right;
             slllast=slltemp;
        }
    slllast->right=sllnewptr;
    sllnewptr->right=NULL;
    slllast=slllast->right;
   
}
void sllInsertMiddle(){
    int pos,counter=2;
    cout<<"\n Enter position to insert Data\n";
    cin>>pos;
    sllnewptr=(struct sll*)malloc(sizeof(struct sll));
    cout<<"\nEnter Data\n";
    cin>>sllnewptr->info;
    slltemp=sllfirst;
    while(slltemp!=NULL){
        if(counter==pos){
            sllprev=slltemp;
            sllnext=slltemp->right;
            sllprev->right=sllnewptr;
            sllnewptr->right=sllnext;
            break;
        }
        else{
            slltemp=slltemp->right;
            counter++;
        }
    }
}
void sllDeleteBegining(){
    if(sllfirst==NULL){
        cout<<"\nThe List is Empty\n";
        return;
    }
     slltemp = sllfirst;
     cout<<"\nDeleted Value is \""<<slltemp->info<<"\"\n";
     sllfirst = sllfirst->right;
     slltemp->right = NULL;
     free(slltemp);
}
void sllDeleteMiddle(){
    int pos,counter=1;
    cout<<"\n Enter position to Delete data from\n";
    cin>>pos;
    slltemp=sllfirst;
    while(slltemp!=NULL){
        if(counter==pos){
            sllnext=slltemp->right;
            sllprev->right=sllnext;
            slltemp->right=NULL;
            cout<<"\nDeleted Data is "<<slltemp->info<<"\n";
            free(slltemp);
            break;
        }
        else{
            sllprev=slltemp;
            slltemp=slltemp->right;
            counter++;
        }
    }

}
void sllDeleteEnd(){
     slltemp=sllfirst;
     while(slltemp->right!=NULL){
             sllprev=slltemp;
             slltemp=slltemp->right;
             slllast=slltemp;
        }
     cout<<"\nDeleted Value is \""<<slllast->info<<"\"\n";
     sllprev->right=NULL;
     slllast=sllprev;
     free(slltemp);      
}


// --Doubly Linked List--
struct dll{
    int info;
    struct dll *right;
    struct dll *left;
}*dlltemp,*dllprev,*dllnewptr,*dllnext,*dlllast,*dllfirst;
int dllCreate()
{
    	char ch;
	while(1)
	{
		dllnewptr=(struct dll*) malloc(sizeof(struct dll));
		cout<<"\nEnter data";
		cin>>dllnewptr->info;
		dllnewptr->right=NULL;
		dllnewptr->left=NULL;
		if(dllfirst==NULL)
		  dllfirst=dlltemp=dllnewptr;
		   else
			{
				dlltemp->right=dllnewptr;
				dllnewptr->left=dlltemp;
				dlltemp=dlltemp->right;
			}
		cout<<"Want to add more elements(y/n)";
		ch=getch();
		if(ch=='n'||ch=='N')
         return(0);	
	dlltemp=dllfirst;
	while(dlltemp->right!=NULL)
	{
		dlltemp=dlltemp->right;
		dlllast=dlltemp;
	}	      
   }

}
void dllDisplayForward(){
    dlltemp=dllfirst;
	cout<<"\nForward display--[\t";
	while(dlltemp!=NULL)
	{
		cout<<dlltemp->info<<"\t";
		dlltemp=dlltemp->right;
	}
    cout<<"]";

}
void dllDisplayBackward(){
    dlltemp=dllfirst;
	while(dlltemp->right!=NULL)
	{
		dlltemp=dlltemp->right;
		dlllast=dlltemp;
	}
	dlltemp=dlllast;
    cout<<"Display Backward--[\t";
	while(dlltemp!=dllfirst)
	{
		cout<<dlltemp->info<<"\t";
		dlltemp=dlltemp->left;	
	}
	cout<<dllfirst->info<<"\t]\n";

}
void dllInsertBegining(){
   dllnewptr=(struct dll*) malloc(sizeof(struct dll)); 	  	
   cout<<"\nEnter Data ";
   cin>>dllnewptr->info;
   dllnewptr->left=NULL;
   dllfirst->left=dllnewptr;
   dllnewptr->right=dllfirst;
   dllfirst=dllnewptr;
}
void dllInsertMiddle(){
    int pos,counter=0;
	dllnewptr=(struct dll*) malloc(sizeof(struct dll)); 
	cout<<"\nEnter the position  at which data is to be entered";
	cin>>pos;	  	
	cout<<"\nEnter data ";
	cin>>dllnewptr->info;
	dlltemp=dllfirst;
	while(dlltemp->right!=NULL)
	{
		counter++;
		if(counter==pos)
		{
			dllprev=dlltemp->left;
			dllprev->right=dllnewptr;
			dllnewptr->left=dllprev;
			dlltemp->left=dllnewptr;
			dllnewptr->right=dlltemp;
		}
		dlltemp=dlltemp->right;
	}

}
void dllInsertEnd(){
   dllnewptr=(struct dll*) malloc(sizeof(struct dll)); 	  	
   cout<<"\nenter data ";
   cin>>dllnewptr->info;
   dllnewptr->right=NULL;
   dlllast->right=dllnewptr;
   dllnewptr->left=dlllast;
   dlllast=dllnewptr;

}
void dllDeleteBegining(){
    dlltemp=dllfirst;
	dllfirst=dllfirst->right;
	dllfirst->left=NULL;
	dlltemp->right=NULL;
    cout<<"\nDeleted Value is  \""<<dlltemp->info<<"\"\n";
	free(dlltemp);

}
void dllDeleteMiddle(){
    int pos,counter=1;
    cout<<"\n Enter position to Delete data from\n";
    cin>>pos;
    dlltemp=dllfirst;
    while(dlltemp!=NULL){
        if(counter==pos){
            dllnext=dlltemp->right;
            dllprev=dlltemp->left;
            dllprev->right = dllnext;
            dllnext->left=dllprev;
        
            dlltemp->right=NULL;
            dlltemp->left=NULL;
            cout<<"\nDeleted Data is \""<<dlltemp->info<<"\"\n";
            free(dlltemp);
            break;
        }
        else{
            dlltemp=dlltemp->right;
            counter++;
        }
    }

}
void dllDeleteEnd(){

    dlltemp=dllfirst;
	while(dlltemp->right!=NULL)
	{
		dlltemp=dlltemp->right;
		dlllast=dlltemp;
	}
    dlltemp=dlllast;
	dlllast=dlllast->left;
	dlllast->right=NULL;
	dlltemp->left=NULL;
    cout<<"\n Deleted Element is \""<<dlltemp->info<<"\"\n";
	free(dlltemp);

}


// ----Hash Map---
struct Person {
    int id;
    std::string name;
};
std::unordered_map<int, std::string> hashMap;
// Custom hash function for MyClass
void HashMapFunctionCreateEntry(){
    int key;string value;
    cout<<"Enter Key(integer) and Value(string) respectively\n";
    cin>>key>>value;
    if(hashMap.count(key) == 0)
    {
    hashMap.insert(std::make_pair(key, value));
    return;
    }
    else{
        cout<<"\nValue already exist with such key\n";
        return;
    }

}
void HashMapFunctionUpdateEntry(){
    int changeKey; string value;
    cout<<"Enter Key for which value should be changed\n";
    cin>>changeKey;
    if(hashMap.count(changeKey) > 0)
    {
        cout<<"Enter New Value for key "<<changeKey<<"\t";
        cin>>value;
        hashMap[changeKey]=value;
        return;
    }
    else{
         cout<<"There is no such element with Key"<<changeKey<<"\t";
         return;
    }

} 
void HashMapFunctionDeleteEntry(){
     int delKey; string value;
    cout<<"Enter Key for which value should be deleted\n";
    cin>>delKey;
    if(hashMap.count(delKey) > 0)
        {
        hashMap.erase(delKey);
        cout<<"Value Deletedwith Key "<<delKey<<endl;
        return;
        }
    else{
        cout<<"There is no such element with Key"<<delKey<<"\t";
        return;
    }
}
void HashMapFunctionDiplayAllEntry(){
    if(hashMap.size()>0){
    cout<<"\nThe Hash List is :\n";
      for (const auto& pair : hashMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    return;
    }
    else{
        cout<<"\tHash table is empty\n";
        return;
    }
}

// ---Graph---
class Graph {
public:
    // Constructor
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    // Add an edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    // Delete an edge from the graph
    void deleteEdge(int src, int dest) {
        auto it = std::find(adjList[src].begin(), adjList[src].end(), dest);
        if (it != adjList[src].end()) {
            adjList[src].erase(it);
        }
    }

    // Print the adjacency list representation of the graph
    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
           cout << "Vertex " << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout <<endl;
        }
    }

private:
    int numVertices;                  // Number of vertices in the graph
    vector<std::vector<int>> adjList;  // Adjacency list representation
};


// --Binary Tree---
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value):data(value),left(nullptr),right(nullptr){}
};

class BinaryTree{
    private:Node* root;
    public:
    BinaryTree(){
        root=nullptr;
    }

    void insertNode(int value){
        root=insertNodeRecursive(root,value);
    }

    Node* insertNodeRecursive(Node* currentNode,int value){
        if(currentNode==nullptr){
            return new Node(value);
        }
        if(currentNode->data>value){
            currentNode->left= insertNodeRecursive(currentNode->left,value);
        }
        else{
            currentNode->right= insertNodeRecursive(currentNode->right,value);
        }

        return currentNode;
    }

    void preorderTreeTraversal(){
        preRecursive(root);
    }

    void preRecursive(Node* currentNode ){
        if(currentNode!=nullptr){
            cout<<currentNode->data<<"  ";
            preRecursive(currentNode->left);
            preRecursive(currentNode->right);
        }
    }

     void inorderTreeTraversal(){
        inRecursive(root);
    }

    void inRecursive(Node* currentNode ){
        if(currentNode!=nullptr){
            inRecursive(currentNode->left);
            cout<<currentNode->data<<"  ";
            inRecursive(currentNode->right);
        }
    }

     void postorderTreeTraversal(){
        postRecursive(root);
    }

    void postRecursive(Node* currentNode ){
        if(currentNode!=nullptr){
            postRecursive(currentNode->left);
            postRecursive(currentNode->right);
            cout<<currentNode->data<<"  ";
        }
    }
};









//--------Main--------
int main()
{
    int mainMenuOption,subMenuOption;
   do
   {
    mainMenuOption=subMenuOption=0;
    cout << "\n\nDATA STRUCTURES\n\n";
    cout << "1.Stack" << endl;
    cout << "2.Queue" << endl;
    cout << "3.Circular Queue" << endl;
    cout << "4.Linked List" << endl;
    cout << "5.Doubly Linked List" << endl;
    cout << "6.Binary Tree" << endl;
    cout << "7.Hash Table" << endl;
    cout << "8.Graphs" << endl;
    cout << "9.Linear Search" << endl;
    cout << "10.Binary Search" << endl;
    cout << "11.Bubble Sort" << endl;
    cout << "12.Selection Sort" << endl;
    cout << "13.Insertion Sort" << endl;
    cout << "14.Exit" << endl;
    cout << "\nEnter and Option\n\n";
    cin >> mainMenuOption;

    //Stack-----------------------------
    if(mainMenuOption==1){
        do
        {    
        cout << "\n\nSTACK\n\n";
        cout<<"1.Push Element"<<endl;
        cout<<"2.Pop Element"<<endl;
        cout<<"3.Display Stack"<<endl;
        cout<<"4.Back To MainMenu"<<endl;
        cout<<"Choose Your Option"<<endl;
        cin>>subMenuOption;
        switch (subMenuOption)
            {
                case 1:
                    stackPush();
                    break;
                case 2:
                    stackPop();
                    break;
                case 3:
                    stackDisplay();    
                default:
                    break;
            }
        } while (subMenuOption!=4); 
    }
   
    //QUEUE-----------------------------
    else if(mainMenuOption==2){
        do
        {
        cout << "\n\nQUEUE\n\n";
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Element"<<endl;
        cout<<"3.Display Queue"<<endl;
        cout<<"4.Back To MainMenu"<<endl;
        cin>>subMenuOption;
        switch (subMenuOption)
            {
                case 1:
                    queueInsert();
                    break;
                case 2:
                    queueDelete();
                    break;
                case 3:
                    queueDisplay();    
                default:
                    break;
            }
        } while (subMenuOption!=4); 
    }
   
    //CIRCULAR QUEUE--------------------
    else if(mainMenuOption==3){
        do
        {
        cout << "\n\nCIRCULAR QUEUE\n\n";
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Element"<<endl;
        cout<<"3.Display Queue"<<endl;
        cout<<"4.Back To MainMenu"<<endl;
        cin>>subMenuOption;
        switch (subMenuOption)
            {
                case 1:
                    CqueueInsert();
                    break;
                case 2:
                    CqueueDelete();
                    break;
                case 3:
                    CqueueDisplay();    
                default:
                    break;
            }
        } while (subMenuOption!=4); 
    }
   
    //LINKED LIST-----------------------
    else if(mainMenuOption==4){
        do
        {
        cout << "\n\nLINKED LIST\n\n";
        cout<<" 1.Create\n";
        cout<<" 2.DisplayForward\n";
        cout<<" 3.Insert Begining\n";
        cout<<" 4.Insert Middle\n";
        cout<<" 5.Insert End\n";
        cout<<" 6.Delete Begining\n";
        cout<<" 7.Delete Middle\n";
        cout<<" 8.Delete End\n";
        cout<<" 9.Back to Main Menu\n";
        cin>>subMenuOption;


    switch(subMenuOption)
	{
		case 1:sllCreate();break;
		case 2:sllDisplayForward();break;
		case 3:sllInsertBegining();break;
		case 4:sllInsertMiddle();break;
		case 5:sllInsertEnd();break;
		case 6:sllDeleteBegining();break;
		case 7:sllDeleteMiddle();break;
		case 8:sllDeleteEnd();break;
	}

        } while (subMenuOption!=9); 
    }
    
    //DOUBLY LINKED LIST----------------
    else if(mainMenuOption==5){
          do
        {
        cout << "\n\n DOUBLY LINKED LIST\n\n";
        cout<<" 1.Create\n";
        cout<<" 2.DisplayForward\n";
        cout<<" 3.DisplayBackward\n";
        cout<<" 4.Insert Begining\n";
        cout<<" 5.Insert Middle\n";
        cout<<" 6.Insert End\n";
        cout<<" 7.Delete Begining\n";
        cout<<" 8.Delete Middle\n";
        cout<<" 9.Delete End\n";
        cout<<"10.Back to Main Menu\n";
        cin>>subMenuOption;

        switch(subMenuOption)
	{
		case 1:dllCreate();break;
        case 2:dllDisplayForward();break;
		case 3:dllDisplayBackward();break;
		case 4:dllInsertBegining();break;
		case 5:dllInsertMiddle();break;
		case 6:dllInsertEnd();break;
		case 7:dllDeleteBegining();break;
		case 8:dllDeleteMiddle();break;
		case 9:dllDeleteEnd();break;
	}
 
        } while (subMenuOption!=10); 
    }

    else if(mainMenuOption==6){
        BinaryTree Btree;
        do{
            cout<<"\n\nBINARY TREE\n\n";
            cout<<"1.Insert a Node\n";
            cout<<"2.PRE Order Traversal\n";
            cout<<"3.IN Order Traversal\n";
            cout<<"4.POST Order Traversal\n";
            cout<<"5.Back To  Main Menu\n";
            cin>>subMenuOption;

            if(subMenuOption==1){
                int nodeval;
                cout<<"\nEnter Node Value\n";
                cin>>nodeval;
                Btree.insertNode(nodeval);
            }
            else if(subMenuOption==2){
            cout<<"2.PRE Order :";
            Btree.preorderTreeTraversal();
            }
            else if(subMenuOption==3){
            cout<<"2.IN Order :";
            Btree.inorderTreeTraversal();

            }
            else if(subMenuOption==4){
            cout<<"2.POST Order :";
            Btree.postorderTreeTraversal();
            }
            else;

        }while(subMenuOption!=5);
    }

    else if(mainMenuOption==7){
        do{
            cout << "\n\nHASH TABLE\n\n";
            cout<<"1.Create table new entry\n";
            cout<<"2.Update Entry\n";
            cout<<"3.Delete entry\n";
            cout<<"4.Display all entries \n";
            cout<<"5.Back to main menu\n";
            cin>>subMenuOption;
            switch(subMenuOption){
                case 1: HashMapFunctionCreateEntry();break;
                case 2: HashMapFunctionUpdateEntry();break;
                case 3: HashMapFunctionDeleteEntry();break;
                case 4: HashMapFunctionDiplayAllEntry();break;

            }
        }while(subMenuOption!=5);
    }
      else if(mainMenuOption==8){
            int numVertices;
            cout << "Enter the number of vertices in the graph: ";
            cin >> numVertices;

            // Create a graph with the specified number of vertices
             Graph graph(numVertices);

            int src, dest;
            int numEdges;
            std::cout << "Enter the number of edges: ";
            std::cin >> numEdges;

            std::cout << "Enter the edges (source destination):" << std::endl;
            for (int i = 0; i < numEdges; ++i) {
                std::cin >> src >> dest;
                graph.addEdge(src, dest);
            }
        do{
            cout << "\n\nGRAPH\n\n";
            cout<<"1.Add an Edge\n";
            cout<<"2.Delete an Edge\n";
            cout<<"3.Display the Graph \n";
            cout<<"4.Back to main menu\n";
            cin>>subMenuOption;
            if(subMenuOption==1){
                int src, dest;
                cout << "Enter the edges (source destination):" << std::endl;
                cin >> src >> dest;
                graph.addEdge(src, dest);    
            }
            else if(subMenuOption==2){
                int src, dest;
                cout << "Enter the edges (source destination) of edge to be deleted:" <<endl;
                cin>>src>>dest;
                graph.deleteEdge(src,dest);
                cout<<"("<<src<<") --> ("<<dest<<")  is Deleted";
            }
            else if(subMenuOption==3){
                cout<<"\n\n GRAPH \n\n";
                graph.printGraph();
            }
            else;
        }while(subMenuOption!=4);
    }
    
    //LINEAR SEARCH---------------------
    else if(mainMenuOption==9){
        do
        {
        cout << "\n\nLINEAR SEARCH\n\n";
        cout<<"1.Perform Linear Search"<<endl;
        cout<<"2.Back To MainMenu"<<endl;
        cin>>subMenuOption;
        if(subMenuOption==1)
            linearSearch();
        } while (subMenuOption!=2); 
    }
    
    //BINARY SEARCH---------------------
    else if(mainMenuOption==10){
        do
        {
        cout << "\n\nBINARY SEARCH\n\n";
        cout<<"1.Perform Binary Search"<<endl;
        cout<<"2.Back To MainMenu"<<endl;
        cin>>subMenuOption;
        if(subMenuOption==1)
            binarySearch();
        } while (subMenuOption!=2); 
    }

    // BUBBLE SORT----------------------
    else if(mainMenuOption==11){
       do
        {
        cout << "\n\nBUBBLE SORT\n\n";
        cout<<"1.Perform Bubble Sort"<<endl;
        cout<<"2.Back To MainMenu"<<endl;
        cin>>subMenuOption;
        if(subMenuOption==1)
            bubbleSort();
        } while (subMenuOption!=2);  
    }

    // SELECTION SORT-------------------
    else if(mainMenuOption==12){
        do
        {
        cout << "\n\nSELECTION SORT\n\n";
        cout<<"1.Perform Selection Sort"<<endl;
        cout<<"2.Back To MainMenu"<<endl;
        cin>>subMenuOption;
        if(subMenuOption==1)
            selectionSort();
        } while (subMenuOption!=2);  
    }

    // INSERTION SORT-------------------
    else if(mainMenuOption==13){
        do
        {
        cout << "\n\nINSERTION SORT\n\n";
        cout<<"1.Perform Insertion Sort"<<endl;
        cout<<"2.Back To MainMenu"<<endl;
        cin>>subMenuOption;
        if(subMenuOption==1)
            insertionSort();
        } while (subMenuOption!=2);  
    }
    
    else{
        cout<<"\nInvalid option\n";
        getch();
        continue;
    }
   } while (mainMenuOption!=14);
    getch();
    return 0;
}