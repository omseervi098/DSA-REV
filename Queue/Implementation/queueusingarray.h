// push o(1) pop (1) and other same
template <typename T> class queue{
    int first;
    int last;
    T * arr;
    int maxcap;
    int size;
    public:
    queue(){
        arr=new T[5];
        maxcap=5;
        size=0;
        first=last=-1;
    }
    void push(T data){
        if(size==maxcap){
            T* newarr=new T(2*maxcap);
            int j=0;
            for(int i=first;i<maxcap;i++){
                newarr[j++]=arr[i];
            }
            for(int i=0;i<first;i++){
                newarr[j++]=arr[i];
            }
            delete [] arr;
            arr=newarr;
            first=0;last=maxcap;
            maxcap=2*maxcap;
        }if(last==-1) first=0;
        last=(last+1)%maxcap;
        arr[last]=data;size++;
    }
    T pop(){
        if(first==last){
            return -1;
        }
        size--;
        if(size==0) first=last=-1;
        first=(first+1)%maxcap;
        return arr[first];
    }
    T front(){
        if(first==last){
            return -1;
        }
        return arr[first];
    }
    int getsize(){
        return size;
    }
    bool empty(){
        return first==last;
    }
};