#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include<string.h>


using namespace std;



void print_vector(vector<int> v){

 for (auto i = v.begin(); i != v.end(); ++i){
 
 
 
 if(*i>9)
{
cout << *i << " ";
}else{

cout <<"0"<<*i << " ";

}

 
        
         
        }


cout<<endl;
}
int in_vector(vector<int> v,int x){

int found=0;

for(int i=0;i<v.size();i++){

if(v[i]==x){

found=1;
break;

}
 
}

  
return found;


}
int index_vector(vector<int> v,int x){

int index;

for(int i=0;i<v.size();i++){

if(v[i]==x){

index=i;
break;

}
 
}

  
return index;


}

 


int main(){


int page=0;

vector<int> input;
vector<int> pages;
int number_of_pages;
cin>>number_of_pages;
string policy;
cin>>policy;
int page_faults=0;

while(page!=-1)
{
cin>>page;
if(page !=-1){
 
 input.push_back(page);
 
}
 
}
if(strcasecmp(policy.c_str(),"optimal")==0)
cout<<"Replacement Policy = OPTIMAL"<<endl;
else if(strcasecmp(policy.c_str(),"lru")==0)
cout<<"Replacement Policy = LRU"<<endl;
else if(strcasecmp(policy.c_str(),"fifo")==0)
cout<<"Replacement Policy = FIFO"<<endl;
else if(strcasecmp(policy.c_str(),"clock")==0)
cout<<"Replacement Policy = CLOCK"<<endl;

cout<<"-------------------------------------"<<endl;
cout<<"Page   Content of Frames"<<endl;
cout<<"----   -----------------"<<endl;


// optimal

int next=0;
int clock[number_of_pages] = {0};


for (int i=0;i<input.size();i++){

page=input[i];



 

if(pages.size() < number_of_pages && !in_vector(pages,page)){                ///////////////////////////// add to empty place if its not a page fault

pages.push_back(page);
clock[index_vector(pages,page)]=1;
if(page>9)
{
cout<<page<<"     ";
}else{

cout<<"0"<<page<<"     ";

}



print_vector(pages);

 
}
else if(in_vector(pages,page)==1){                                              ////////////////////////////////// if it exists

if(page>9)
{
cout<<page<<"     ";
}else{

cout<<"0"<<page<<"     ";

}


print_vector(pages);


clock[index_vector(pages,page)]=1;


}


else if(pages.size()==number_of_pages && in_vector(pages,page)==0){

 page_faults++; // if it entyered this condition this means a page fault was found
   

// replacment policy

if(strcasecmp(policy.c_str(),"optimal")==0){


int furthest=i,furthest_page;
int j;
for(int y=0;y<number_of_pages;y++){

  for( j=i;j<input.size();j++){
  // if element is found 
     if(input[j]==pages[y]){
     
     if(j>furthest){
     furthest=j;
     furthest_page=y;
     }
     // no need to continou as element is found 
     break;
     
     
     }
  
  
  
  
  }
// if element was never found 
if(j==input.size()){
furthest_page=y;
break;

}
}

pages.at(furthest_page)=page;

if(page>9)
{
cout<<page<<" F   ";
}else{

cout<<"0"<<page<<" F   ";

}


print_vector(pages);

}else if(strcasecmp(policy.c_str(),"lru")==0){


int furthest=i,furthest_page;
int j;
for(int y=0;y<number_of_pages;y++){

  for( j=i;j>=0;j--){
  // if element is found 
     if(input[j]==pages[y]){
     
     if(j<furthest){
     furthest=j;
     furthest_page=y;
     }
     // no need to continou as element is found 
     break;
     
     
     }
  
  
  
  
  }
// if element was never found 
if(j==input.size()){
furthest_page=y;
break;

}
}

pages.at(furthest_page)=page;

if(page>9)
{
cout<<page<<" F   ";
}else{

cout<<"0"<<page<<" F   ";

}


print_vector(pages);




}// end of lru

else if(strcasecmp(policy.c_str(),"fifo")==0){



 next=next%number_of_pages;
pages.at(next)=page;


if(page>9)
{
cout<<page<<" F   ";
}else{

cout<<"0"<<page<<" F   ";

}


print_vector(pages);





next++;

}
//clock
else if(strcasecmp(policy.c_str(),"clock")==0){                                           




for(int c=0;c<=number_of_pages+1;c++){


if(clock[next%number_of_pages]==0){
pages.at(next%number_of_pages)=page;
clock[next%number_of_pages]=1;
next++;
break;
}else{

clock[next%number_of_pages]=0;
next++;
}


}



if(page>9)
{
cout<<page<<" F   ";
}else{

cout<<"0"<<page<<" F   ";

}


print_vector(pages);








}











}// replacment condition
 
 





}


cout<<"-------------------------------------"<<endl;
cout<<"Number of page faults = "<<page_faults<<endl;







}
