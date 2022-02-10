
/*#include<iostream>

using namespace std;

class TT{

  static int r;

  int a,b;

public:

  TT(int i,int j){a=i;b=j;r++;}

  int Getr(){return a+b+r;}

};

int TT::r=0;

int main(){

  TT t1(2,3);

  cout<<t1.Getr()<<endl;

  TT t2(3,4);

  cout<<t2.Getr()<<endl;

  return 0;

}
#include<iostream>
using namespace std;
class A{

private:

	int a;

public:

	A(int aa=0):a(aa){cout<<a<<"  ";}

	~A(){cout<<"析构";}

};

int main()

{

	A x[3]={1,2};

	cout<<endl;

    return 0;

}
#include<iostream>
#include<fstream>
#include <stdlib.h>
using namespace std;
int main(){

   fstream file;

   file.open("tl.dat",ios::in|ios::out);

   if(!file){

      cout<<"tl.dat can't open.\n";

      abort();

   }

   char s[]="abcdegf\123465";

   for(int i=0; i<sizeof(s); i++)

	   file<<s[i];

   file.seekg(5);

   char ch;

   while(file.get(ch))

	   cout<<ch;

   file.close();

}

#include <iostream>

using namespace std;

int main(){

   const double PI=31.415;

   cout.width(10);

   cout.fill('*');

   cout<<internal<<PI<<endl;      //第一空

   cout<<scientific<<left<<showpos<<PI<<endl;    //第二空

}
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int k=10;
    cout<<"k="<<hex<<k<<endl;        //第一空
    float d=123.4567;
    cout<<"d="<<setw(10)<<setprecision(5)<<setfill('*')<<dec<<d<<endl;    //第二空

}
*/
