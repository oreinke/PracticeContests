// #include <iostream>
// #include <iomanip>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;
#define height 1.0
//must round to 2 dcemial places
//each frame built will be 1 inch deep
//4 width, 6 length, and 1 diagnoal equals 16.14 somehow
//so we need to get the pythagorym theorem , we have the hypotonuse and we know its 45 degres.
//we know the legnth will be diagonal/sqrt(2).
//maybe calculate two squares, the inner and outer, and then subtract them?

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n; // number of group members
        cin >> n;
        vector<float> groupvolumes;
        for(int i=0;i<n;i++){

            int frames;
            cin >> frames;
            vector<float> differences;
            for(int i=0;i<frames;i++){
                float length, width, diag;
                cin >> length >> width >> diag;
                //maybe get the volume first of the two rectangles
                float fullrectangle = length*width*height;
                //divide the diagonal by sqrt(2)
                float side = diag/sqrt(2);
                // cout << "side is: "<< side <<endl;
                float smallwidth = width+(side*2);
                float smalllength = length+(side*2);
                //get the smaller inner rectangle
                float smallerrectangle = smalllength*smallwidth*height;
                //now we subtract the two
                float difference = smallerrectangle - fullrectangle;
                // cout << "full rectangle is: "<< fullrectangle << " smaller is: " << smallerrectangle << endl;
                differences.push_back(difference);
            }
            float total=0;
            for(float difference : differences){
                total += difference;
            }
            groupvolumes.push_back(total);
        }
        float totalvolume  =0;
        for(float volume : groupvolumes){
            totalvolume += volume;
        }

        cout<< setprecision(2) << fixed;
        cout << "group #" << i+1 << ": " << totalvolume << " cubic inches" << endl;
        cout << "\n";

        //we have answer if its flat, but how do we make it volume of 1 inch?

    }

}
