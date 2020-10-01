#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

void my_popen( const string& cmd ,vector<string>& out ){
    FILE*  fp;
    const int sizebuf=1234;
    char buff[sizebuf];
    out = vector<string> ();
    if ((fp = popen (cmd.c_str (), "r"))== NULL){

}
    string cur_string = "";
    while (fgets(buff, sizeof (buff), fp)) {
        cur_string += buff;
}
    out.push_back (cur_string.substr (0, cur_string.size() -1));
    pclose(fp);
}




int main () {

    vector<string> output;
    my_popen("which gcc", output);
    for (vector<string>::iterator itr = output.begin();
        itr != output.end();
        ++itr) {
            cout << *itr << endl;
        }
    return 0;
}
