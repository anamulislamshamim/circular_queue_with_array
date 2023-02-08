#include<bits/stdc++.h>
using namespace std;

class Queue 
{
    public:
        int l,r,sz,cap;
        int * arr;
        Queue()
        {
            l=0;
            r=-1;
            sz=0;
            cap=1;
            arr = new int[1];
        }
        void remove_circulation()
        {
            // if the l>r that means the queue is circular
            if(l>r)
            {
                int * tmp = new int[cap];
                int idx=0;
                for(int i=0;i<cap;i++)
                {
                    tmp[idx] = arr[i];
                    idx++;
                }
                for(int j=0;j<=r;j++)
                {
                    tmp[idx] = arr[i];
                    idx++;
                }
                // update the l and r
                l=0;
                r=cap-1;
                delete [] tmp;
            }
        }
        void increase_size()
        {
            // remove the circulation
            remove_circulation();
            int * tmp = new arr[cap*2];
            for(int i=0;i<cap;i++)
            {
                tmp[i] = arr[i];
            }
            swap(tmp,arr);
            // update the cap
            cap*=2;
            delete [] tmp;
        }

        void enqueue(int value)
        {
            if(sz==cap)
            {
                increase_size();
            }
            r++;
            if(r==cap)
            {
                r=0;
            }
            arr[r] = value;
        }
        void dequeue()
        {
            if(sz==0)
            {
                cout << "The queue is empty!" << "\n";
                return;
            }
            l++;
            if(l==cap)
            {
                l=0;
            }
        }
        int qfront()
        {
            if(sz==0)
            {
                cout << "The queue is empty!" << "\n";
                return -1;
            }
            return arr[l];
        }
        int Size()
        {
            return sz;
        }
}

int main()
{
    cout << "Hello World" << "\n";
    return 0;
}
