
#include<iostream>
#include<fstream>
#include<cpr/cpr.h>
#include <unistd.h>
#include<string>
#include<regex>
#include"json.hpp"
#include<vector>
using namespace std;
using json = nlohmann::json;

bool mypermission(){
string mykey = "a9T72mQ58xL40RpFd";
string url = "https://raw.githubusercontent.com/wrong00001/permision1/main/code.txt";
sleep (2);
auto req = cpr::Get(cpr::Url{url});
sleep (3);
if (req.status_code != 200 ){
    cout<<"Server error";
}
string serverKey = req.text;
while (!serverKey.empty() && 
       (serverKey.back() == '\n' || serverKey.back() == '\r' || serverKey.back() == ' '))
{
    serverKey.pop_back();
    cout<<serverKey;
}
return (mykey == serverKey);
}

void working(){
     cout<<"------------TOOL IS RUNNING NOW (KHAN'S OWNER)------------\n";
string myapi = "5a59347f1de48c161c8c6539a52add34";
string mycity;
cout<<"Please enter phone number or cnic (like Phone number:(03...))/(cnic:(350...)):";
cin>>mycity;
string url = "https://simlivetracker.xyz/wp-content/plugins/livetrackers-plugin/search.php?type=mobile&search=" + mycity;
auto response = cpr::Get(cpr::Url{url});
  if(response.error){
    cout<<"Network probelm :"<<response.status_code<<endl;
     cout<<"Error :"<<response.error.message<<endl;
  }
if (response.status_code != 200) {
        cout << "Failed to fetch page. Status code: " << response.status_code << endl;
    }
     string html = response.text; 
 size_t pos = 0;

    while (true) {
        // Find <td ...> for one row
        size_t start = html.find("<td", pos);
        if (start == string::npos) break; // no more rows

        cout << "\n"; // row separator
        for (int col = 0; col < 4; col++) { // 4 columns, generalize by changing number
            start = html.find(">", start) + 1; // start after >
            size_t end = html.find("</td>", start); // end of cell
            string cell = html.substr(start, end - start);
            if (cell.empty()) cell = "(empty)";
            
            switch(col) {
                case 0: cout << "Number: " << cell << "\n"; break;
                case 1: cout << "Name: " << cell << "\n"; break;
                case 2: cout << "CNIC: " << cell << "\n"; break;
                case 3: cout << "Address: " << cell << "\n"; break;
            }
            start = end + 5; // move past </td>
        }
        cout << "-----------------------------------\n";
        pos = start;
    }


}

int main (){
    int choose;
while(true){
    cout<<"\nSelect 1 for Run or 0 for Exit :";
    cin>>choose;
    if (choose==1){
     if(!mypermission()){ 
         exit(1);  
}
    working();
     continue;
    } if(choose==0){

        exit(1);
    }else{
        cout<<"choose correct one.";
    continue; 
   }
}

}