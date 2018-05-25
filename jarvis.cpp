//This chatbot version tries to understand user input.It responds on the basis of keywords.

#include<bits/stdc++.h>
using namespace std;
const int max_resp=3;

typedef vector<string> vstring;//to make easy for reference.

vstring find_match(string input);
void copyfunc(char *arr[],vstring &v);

typedef struct {
    char *input;
    char *responses[max_resp];
}record;

record knowledgedb[] = {
    {"WHAT IS YOUR NAME",
    {"MY NAME IS JARVIS",
     "YOU CAN CALL ME JARVIS",
     "WHY DO YOU WANT TO KNOW MY NAME?"}
    },

    {"HI",
    {"HI THERE!",
     "HOW ARE YOU?",
     "HI!"}
    },

    {"HOW ARE YOU",
    {"I'M DOING FINE!",
    "I'M DOING WELL AND YOU?",
    "WHY DO YOU WANT TO KNOW HOW AM I DOING?"}
    },

    {"WHO ARE YOU",
    {"I'M AN A.I PROGRAM.",
     "I THINK THAT YOU KNOW WHO I'M.",
     "WHY ARE YOU ASKING?"}
    },

    {"ARE YOU INTELLIGENT",
    {"YES,OFCORSE.",
     "WHAT DO YOU THINK?",
     "ACTUALY,I'M VERY INTELLIGENT!"}
    },

    {"ARE YOU REAL",
    {"DOES THAT QUESTION REALLY MATERS TO YOU?",
     "WHAT DO YOU MEAN BY THAT?",
     "I'M AS REAL AS I CAN BE."}
    },

    {"WHAT DO YOU KNOW ABOUT HUMANS",
    {"MY CREATOR IS A HUMAN ONLY",
     "THEY ARE VERY INTELLIGENT",
     "HUMANS HAVE BRAIN"}
    }
};

size_t knowledgedbsize=sizeof(knowledgedb)/sizeof(knowledgedb[0]);


int main(void) {
	srand((unsigned) time(NULL));
	string input;
	string output;

    while(true)
    {
        cout<<"->";
        getline(cin,input);
        for(auto & c : input) c = toupper(c);// to convert to uppercase.
        vstring responses = find_match(input);
        if(input == "BYE")
        {
        	cout<<"IT WAS NICE TALKING TO YOU, SEE YOU AGAIN!"<<endl;
        	break;
        }
        else if(responses.size() ==0)//no match found
        {
        	cout<<"I DON'T UNDERSTAND WHAT YOU ARE SAYING"<<endl;

        }
        else
        {
        	int indexselect = rand()%max_resp;
            output=responses[indexselect];
            cout<<output<<endl;
        }
    }
    return 0;
}

//search for keyword in the keyword database
vstring find_match(string input) {
	vstring result;
	for(int i=0;i<knowledgedbsize;i++)
	{
		if(string(knowledgedb[i].input)==input){
			copyfunc(knowledgedb[i].responses,result);
		}
	}
	return result;
}

void copyfunc(char *arr[],vstring &v) {
	for(int i=0;i<max_resp;i++) {
		v.push_back(arr[i]);
	}
	return ;
}
