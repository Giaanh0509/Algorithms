#include<bits/stdc++.h> 
#include<cstdlib>
#include<string>

using namespace std ; 


unsigned long long checkphone=0, total ; 
vector<unsigned long long> out1 ; 
string s, fromnumber, tonumber, date, kphone, fromtime, totime; 
map<string, unsigned long long> listphone ;
map<string, unsigned long long> secondphone ;


bool checkPhone(string phonenumber)
   {
   	 bool check = true ;
   	 if(phonenumber.size() == 10 )
   	  {
   	  	 for(unsigned i=0; i < phonenumber.size(); i++) 
   	  	  if(phonenumber[i] > '9') 
   	  	    {
   	  	    	check = false ;
   	  	    	break ; 
			}
	  }
	 else check = false ; 
	  
	  return check ; 
   }


int exchange(string time) 
   {
   	 unsigned long long second ; 
   	 string h = time.substr(0,2) ; 
   	 string m = time.substr(3,5) ;
   	 string s = time.substr(6,8) ;
   	 unsigned long long hour = atoi(h.c_str())*3600 ;
   	 unsigned long long min = atoi(m.c_str())*60 ;
   	 unsigned long long sec = atoi(s.c_str()) ;
   	 second = hour + min + sec ; 
   	 return second  ; 
   }



void input() {
	 while(true) 
      {
      	 cin >> s ;
      	 if(s == "#") 
		   { break ;
		   }
      	 else 
      	  {  
      	     total++ ; 
      	  	 cin >> fromnumber ; 
      	  	 listphone[fromnumber]++ ; 
      	  	 cin >> tonumber ; 
      	  	 if(checkPhone(fromnumber) != true) checkphone++ ; 
      	  	 if(checkPhone(tonumber) != true) checkphone++ ;
      	  	 cin >> date ; 
      	  	 cin >> fromtime ; 
      	  	 cin >> totime ; 
      	  	 secondphone[fromnumber] += exchange(totime) - exchange(fromtime) ;
		  }
	  }
	  
     
     while(true) 
      {
      	cin >> s ;
      	 if(s == "#") 
		   { break ;
		   } 
		 else { 
		   if (s == "?check_phone_number")
		     {
		       if(checkphone == 0) out1.push_back(1) ; 
		        else out1.push_back(0) ; 
			 }
		   else if (s == "?number_calls_from")
		    {
		      	cin >> kphone ; 
		      	out1.push_back(listphone[kphone]) ; 
		    } 
		    else if(s == "?number_total_calls")
		     {
		     	out1.push_back(total) ; 
 			 }
 			else if(s == "?count_time_calls_from")
 			 {
 			 	cin >> kphone ; 
 			 	out1.push_back(secondphone[kphone]) ;
			}
		 }
      }
 	 
}

void print() 
   {
   	 for(unsigned long long i=0; i < out1.size(); i++) 
 	   { 
 	      cout << out1[i] << endl ; 
	 	}
   }
   
   
int main() 
   { 
     input() ; 
     print() ; 
     return 0 ; 
   }
