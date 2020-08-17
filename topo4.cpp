//***************************************header files
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cfloat>
#include <fstream>


#define X 400
#define Y 400
#define size 100 
#define radius 75
#define K 4
using namespace std;



//*****************************************declaring new data type ordinate
class ordinate {
public:
int x[size];
int y[size];
};



//**************************************** function that calculates the distance
float dist (int p,int q ,int r, int s)
	{
	int m ,n;
	double dis;
		m = pow ((p-q) , 2);
		n = pow ((r-s) , 2);
		
		dis = sqrt (m + n);	
	return dis;
	}


/*****************************************Global declarations*************************/
double table[size][size];
ordinate node[size];
double yaodist[size][K];
double yaoedge[size][K];



// ****************************************main loop 
int main()
	{

	
	int count;
	int i,j,k,l;// variables used for a loop
	double d;
	ofstream myfile;
	float dist (int , int , int , int);
	

	int a,b,c = 0;
	float small;
	float numbseq[size]; // elements for getting a smallest number in Quadrant
	int temp,t;
	int nodeseq[size];	
	float v=0;// using to set numbseq to zero



//*****************************************generation of random nodes 
		cout<< " we ll be generating node\n";

		for (count =0; count < size; count++ )
		{
			node -> x[count] = (1 + rand() % X );
			node -> y[count] = (1 + rand() % Y );
		 }




// *****************************************we will be printing the values
		cout << "co-ordinates in form of P(x,y)\n";
		for(i=0 ; i< size ;i++ )
		{
			 cout << "node" << i << "\t" << node -> x[i] <<"," << node-> y[i] << "\n";
		}

// ******************************************we will calculate the distance between two nodes
		for (j= 0; j< size; j++)
		{// this represnts row
			for (k= 0; k < size; k++)
			{//this gives column
				if (j == k )
					{//if
					table[j][k] = '0';
					cout << "\n Distance between " << j << " and   " << k <<" is:" << 0 <<"\n";
					}// end of if 
				else
					{//else		
					d = dist(node -> x[j] , node -> x[k] , node -> y[j] ,node -> y[k]);
					cout << "\n Distance between " << j <<" and " << k <<" is:" << d <<"\n";
					table[j][k] = d;
					}//end of else
					

			}//inner for loop
		}// outer for loop



		
// *********************************************Creating a *dot file for Graphviz and we display in terminal
		cout << "\n we created a file showing the nodes that are connected and the distance between them i.e. a *dot file \n"; 
		myfile.open ("finale.dot"); // open a *dot file to write data
		myfile << "graph G " << "\n" << "{" << "\n";
		myfile << "node [shape=circle,style=filled, height=1.4, width=1.4, fontsize=8, color=black];" << "\n";
		myfile << "edge [weight=1.0] ;\n"; 
		for (i= 0; i< size; i++)
		{
			myfile << i << " [pos = \" " << node->x[i] <<"," << node->y[i] <<"!\"]" << "\n";
		}
		
		for (j= 0; j< size; j++)
		{// this represnts row
			for (k= j; k < size; k++)
			{//this gives column
				if (table[j][k] < radius && table[j][k] != 0 && j!=k )
				{
					myfile << "\t" << j << " -- " << k << ";"<< "\n";
				}//end if 
			}//innner for loop
		}//outer for loop
		myfile << "}";	
		myfile.close();// close the file


/************************************************we get the YAO graph details ***********************/
//***********************************************Quadrant 1
cout<< "//***********************************************Quadrant 1" << "\n ";
// **********************************************intialize i,j,k back to zero********************
	i = i -i;
	j = j -j;
	k = k -k;
	c = 0;// count for know number of pts in a quadrant 



 
		for(i=0 ; i< size ;i++ )
		{
			for(j=0 ; j< size; j++) 
			{
				if  (i != j) 
				{ 
					if ((node->x[i] <= node->x[j]) && (node->y[i] <= node->y[j])) 
					{				
					cout<< node->x[j] <<","<< node->y[j] << "\t" <<j <<"\n";
					numbseq[c]= table[i][j];
					nodeseq[c]= j;
					c++;
					}//inner if

				}// end of if loop 
				
			}// end of innner for loop i.e "j"
				
				

										
					// we calcualte the smallest number in the given Quadrant
					k = k- k;//release k
					small = numbseq[0];
					temp = 0;
					for(k=0;k< c;k++)
					{	 
						if(numbseq[k] < small)
							{
							temp = k;	
							small =numbseq[k];
							}
					}
					t = nodeseq[temp];			
					cout << " Smallest Distance in this Quadrant is :" << small <<"@" << t <<"\n";	 
					// end of calculation ********************
				       	
					// here do allocation of nodes and distance				
					yaodist[i][0] = small;
					if (small != 0)
					yaoedge[i][0] = t;
					else
					yaoedge[i][0] =-1;
					
					// here set memset numbseq[] valuoe to zero
					k = k- k;
					for(k=0; k< c; k++)
					{
					numbseq[k]= 0;
					nodeseq[k]= 0;
					}
					c= c - c;// release the counter for next loop
					 


		}// end of outer for loop i.e "i"


//***********************************************Quadrant 2
cout<< "//***********************************************Quadrant2 " << "\n ";
// **********************************************intialize i,j,k back to zero********************
	i = i -i;
	j = j -j;
	k = k -k;
	c = 0;// count for know number of pts in a quadrant 


		for(i=0 ; i< size ;i++ )
		{
			for(j=0 ; j< size; j++) 
			{
				if  (i != j) 
				{ 
					if ((node->x[i] >= node->x[j]) && (node->y[i] < node->y[j])) 
					{				
					cout<< node->x[j] <<","<< node->y[j] << "\t" <<j <<"\n";
					numbseq[c]= table[i][j];
					nodeseq[c]=j;
					c++;
					}//inner if

				}// end of if loop 
				
			}// end of innner for loop i.e "j"
			

					// we calcualte the smallest number in the given Quadrant
					
					small = numbseq[0];
					temp= 0;
					for(k=0;k< c;k++)
					{	 
						if(numbseq[k] < small)
							{
								small =numbseq[k];
								temp = k;
							}
					}			
					t = nodeseq[temp];			
					cout << " Smallest Distance in this Quadrant is :" << small <<"@" << t <<"\n";	 
					// end of calculation ********************
				       	k = k- k;//release k
					// here do allocation of nodes and distance				
					yaodist[i][1] = small;
					if(small != 0)
					yaoedge[i][1] = t;
					else
					yaoedge[i][1] = -1;
					
					// here set memset numbseq[] valuoe to zero
					k = k- k;
					for(k=0; k< c; k++)
					{
					numbseq[k]= 0;
					nodeseq[k]= 0;
					}
					c= c - c;// release the counter for next loop
			
		}// end of outer for loop i.e "i"



//***********************************************Quadrant 3
cout<< "//***********************************************Quadrant 3" << "\n ";
//***********************************************intialize i,j,k back to zero********************
	i = i -i;
	j = j -j;
	k = k -k;
	c = 0;// count for know number of pts in a quadrant 


		for(i=0 ; i< size ;i++ )
		{
			for(j=0 ; j< size; j++) 
			{
				if  (i != j) 
				{ 
					if ((node->x[i] > node->x[j]) && (node->y[i] >= node->y[j])) 
					{				
					cout<< node->x[j] <<","<< node->y[j] << "\t" <<j <<"\n";
					numbseq[c]= table[i][j];
					nodeseq[c]= j;
					c++;
					}//inner if

				}// end of if loop 
				
			}// end of innner for loop i.e "j"
			

					// we calcualte the smallest number in the given Quadrant
					
					small = numbseq[0];
					for(k=0;k< c;k++)
					{	
						temp= 0; 
						if(numbseq[k] < small)
						{
							small =numbseq[k];
							temp =k;	
						}	
					}			
					t = nodeseq[temp];			
					cout << " Smallest Distance in this Quadrant is :" << small <<"@" << t <<"\n"; 
					// end of calculation ********************
				       	k = k- k;//release k
					// here do allocation of nodes and distance					
					yaodist[i][2] = small;
					if(small != 0)
					yaoedge[i][2] = t;
					else
					yaoedge[i][2] = -1;
					
					// here set memset numbseq[] value to zero
					k = k- k;
					for(k=0; k< c; k++)
					{
					numbseq[k]= 0;
					nodeseq[k]= 0;
					}
					c= c - c;// release the counter for next loop
			
		}// end of outer for loop i.e "i"


//***********************************************Quadrant 4
cout<< "//***********************************************Quadrant 4" << "\n ";
//***********************************************intialize i,j,k back to zero********************
	i = i -i;
	j = j -j;
	k = k -k;
	c = 0;// count for know number of pts in a quadrant 



		for(i=0 ; i< size ;i++ )
		{
			for(j=0 ; j< size; j++) 
			{
				if  (i != j) 
				{ 
					if ((node->x[i] < node->x[j]) && (node->y[i] > node->y[j])) 
					{				
					cout<< node->x[j] <<","<< node->y[j] << "\t" <<j <<"\n";
					numbseq[c]= table[i][j];
					nodeseq[c]= j;
					c++;
					}//inner if

				}// end of if loop 
				
			}// end of innner for loop i.e "j"
			

					// we calcualte the smallest number in the given Quadrant
					
					small = numbseq[0];
					temp = 0;
					for(k=0;k< c;k++)
					{	 
						v = v + numbseq[k];// get the sum 
						if(numbseq[k] < small)
							{
							small =numbseq[k];
							temp = k;
							}
					}			
					t = nodeseq[temp];			
					cout << " Smallest Distance in this Quadrant is :" << small <<"@" << t <<"\n"; 
					// end of calculation ********************
				       	k = k- k;//release k
					// here do allocation of nodes and distance					
					yaodist[i][3] = small;
					if(small != 0)
					yaoedge[i][3]= t;
					else
					yaoedge[i][3]= -1; 	
					
					// here set memset numbseq[] valuoe to zero
					k = k- k;
					for(k=0; k< c; k++)
					{
					numbseq[k] = 0;
					nodeseq[k] = 0;
					}
					c= c - c;// release the counter for next loop
			
		}// end of outer for loop i.e "i"




// testing the entering the contents of matrix sizeX K in yaotable
	
	cout<< "\n";
	cout << " The contents of matrix size X K in yaotable which gives the yao Dist \n";
	for (a= 0; a< size; a++ )
		{
		cout <<"Node"<< a << " "<<"Yoa Distance is: ";
		for (b= 0; b<K; b++ )
	  	cout <<yaodist[a][b] <<" ";
		cout <<"\n";
		}
		cout <<"Please note  0 symbolizes that the node is not connected to any node in that sector";
		cout<< "\n";



// test code for checking the yaoedge
	
	cout<< "\n";
	cout << " The contents of matrix size X K in yaotable which gives the yao edges \n";
	for (a= 0; a< size; a++ )
		{
		cout <<"Node"<< a << " "<<"Yoa Distance is: ";
		for (b= 0; b<K; b++ )
	  	cout <<yaoedge[a][b] <<" ";
		cout <<"\n";
		}


// matrix sizeXK in yaoegde , gives all yao node for yao nodes
/*********************************************Creating a Yao.dot file*********************************/
	cout <<"\n";
	cout << "Creating and displaying Yao.dot file :\n";			
	cout << "The contents of matrix size X K in yaotable that gives the Yao nodes  for any nodes\n";
	myfile.open ("Yao.dot"); // open a Yao.dot file to write data
	myfile << "graph G " << "\n" << "{" << "\n";
	myfile << "node [shape=circle,style=filled, height=1.4, width=1.4, fontsize=8, color=black];" << "\n";
	myfile << "edge [weight=1.0] ;\n";
	for (i= 0; i< size; i++)
		{
			myfile << i << " [pos = \" " << node->x[i] <<"," << node->y[i] <<"!\"]" << "\n";
		}
	for (a= 0; a< size; a++ )
		{
		for (b= 0; b< K; b++ )
			{
				if (yaoedge[a][b] != -1 && yaoedge[a][b] != 0)
					{		
					cout << a << "--" << yaoedge[a][b] <<"\n";
					myfile << "\t"<< a << " -- " << yaoedge[a][b] << ";" << "\n";
					}//inner if loop
			}//inner for loop
		}//outer for loop
		myfile << "}";	
		myfile.close();// close the file		
		cout<< "\n";

		


		 
		  
		
/***********************************************The End ****************************************/
	return 1;

	}//main loop





