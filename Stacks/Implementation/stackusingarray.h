//pop -o(1) and push -o(1)
template <typename T>
class stack{
    T *arr;
    int ni;
    int maxcap;
    public:
    stack(){
        arr=new T(5);
        ni=0;
        maxcap=5;
    } 
    void push(int data){
        if(ni==maxcap){
            T* newarr=new T(2*maxcap);
            for(int i=0;i<maxcap;i++){
                newarr[i]=arr[i];
            }
            delete [] arr;
            arr=newarr;
            maxcap=2*maxcap;
        }
        arr[ni++]=data;
    }
    T pop(){
        if(ni==0){
            return -1;
        }
        ni--;
        return arr[ni];
    }
    bool empty(){
        return ni==0;
    }
    int size(){
        return ni;
    }
    T peek(){
        if(ni==0){
            return -1;
        }
        return arr[(ni)-1];
    }
};