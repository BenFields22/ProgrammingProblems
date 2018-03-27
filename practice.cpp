//if string has all unique characters
#include <iostream>
#include <string>
#include <cstring>

class Node{
	int value;
	Node Next = NULL;
	Node(int v){value=v;}
	void append_To_Tail(int v){
		Node end = new Node(d);
		Node n = this;
		while (n.next != null) { 
			n = n.next; 
		} 
		n.next = end;
	}
};



int unique(std::string phrase){
	int length = phrase.length();
	std::cout<<"The length is "<<length<<std::endl;
	for (int i = 0; i < length; ++i){
		for (int j = 0; j< length; ++j){
			if(j == i)continue;
			if (phrase[i] == phrase[j])
			{
				std::cout<<"Failed on character "<<phrase[i]<<std::endl;
				return 0;
			}
		}
	}
	return 1;
}

char* reverse(const char* myString , int len){
	char* newString = new char(len+1);
	newString[len] = '\0';
	for(int i = 0;i<len;++i){
		newString[i] = myString[len-1-i];
	}
	return newString;
}

int main(int argc, char **argv){
  int ans = unique("benjamin");
  if(ans){
  	std::cout<<"String is made of unique characters\n";
  }
  else{
  	std::cout<<"String is not made of unique characters\n";
  }

  std::string phrase = "Ben";

  std::cout<<"Reverse:"<<reverse(phrase.c_str(),3)<<std::endl;


}