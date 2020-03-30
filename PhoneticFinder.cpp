#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "PhoneticFinder.hpp"
// #include "split.hpp"
#include <stdio.h> 

using namespace std;
 
 
 namespace phonetic{

    string find(string text ,string word){
        try{
            std::transform(word.begin(), word.end(),word.begin(), ::tolower);
            cout<<"word: "<<word<<endl;
            vector<string> words=split(word,false);
            int containsWord=0;
            for(int i=0;i<words.size();i++){
                if(words[i]!=""){
                     if(containsWord==0) containsWord++;
                     else
                        __throw_runtime_error("The word must contain only one word");
                }
            }
          
            std::string::iterator end_pos = std::remove(word.begin(), word.end(), ' ');
            word.erase(end_pos, word.end());
            if(word=="")
                __throw_runtime_error("The word cannot be empty");
            
            bool equal;
            vector<string> v1=split(text,false);
            for(int i=0;i<v1.size();i++){ //מעבר על הוקטור של המילים
                if(v1[i].size()==word.size()){// אם גודל המילה שהתקבלה שווה לגודל המילה במיקום בוקטור
                    string temp=v1[i];
                    std::transform(temp.begin(), temp.end(),temp.begin(), ::tolower);
                    if(temp.compare(word)==0){
                        return v1[i];
                    } 
                    for(int j=0;j<word.size();j++){ //מעבר על אותיות המילה כדי לבדוק התאמה
                        equal=false;
                        switch(word.at(j)) {
                            case 'v':
                            case 'w':
                                if(temp.at(j)=='v' || temp.at(j)=='w'){
                                    equal=true;}
                                break;
                            case 'b':
                            case 'f':
                            case 'p':
                                if(temp.at(j)=='b' || temp.at(j)=='f' || temp.at(j)=='p'){
                                    equal=true;}
                                break;
                            case 'g':
                            case 'j':
                                if(temp.at(j)=='g' || temp.at(j)=='j')
                                    equal=true;
                                break;
                            case 'c':
                            case 'k':
                            case 'q':
                                if(temp.at(j)=='c' ||temp.at(j)=='k' || temp.at(j)=='q')
                                    equal=true;
                                break;
                            case 's':
                            case 'z':
                                if(temp.at(j)=='s' || temp.at(j)=='z')
                                    equal=true;
                                break;
                            case 'd':
                            case 't':
                                if(temp.at(j)=='d' || temp.at(j)=='t')
                                    equal=true;
                                break;
                            case 'u':   
                            case 'o':
                                if(temp.at(j)=='o' || temp.at(j)=='u')
                                    equal=true;
                                break;
                            case 'y':   
                            case 'i':
                                if(temp.at(j)=='i' || temp.at(j)=='y')
                                    equal=true;
                                break;
                            default:
                                if(temp.at(j)==word.at(j))
                                    equal=true;
                        }
                        if(!equal)
                            break;
                        if(j==word.size()-1) return v1[i];
                    }
                }
            }
        }catch(char const* message){
            cout << message << endl;
            return "";
        }
            // throw("word doesn't exist in text");
            string str="Did not find the word '";
            str.append(word);
            str.append("' in the text");
            const char * c = str.c_str();
            __throw_runtime_error(c);
            return "";

    };
     vector<string> split(string text, bool caseSen){
        string delimiter = " ";
        vector<string> data;

        size_t pos = 0;
        string token;
        if(caseSen) std::transform(text.begin(), text.end(),text.begin(), ::tolower);
        while ((pos = text.find(delimiter)) != std::string::npos) {
            token = text.substr(0, pos);
            data.push_back(token);
            text.erase(0, pos + delimiter.length());
        }
        data.push_back(text);
        return data;
    }
 };