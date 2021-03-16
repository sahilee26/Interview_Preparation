int min_elem;
stack<int> s;

MinStack::MinStack() {
    s= stack<int> ();
}

void MinStack::push(int x) {
    if(s.empty()){
        s.push(x);
        min_elem=x;
    }
    else{
        if(x>=min_elem){
            s.push(x);
        }
        else{
            s.push(2*x-min_elem);
            x=min_elem;
        }
    }
}

void MinStack::pop(){
    if(s.empty())
        return;
    else{
        int y=s.top();
        if(y<min_elem)
            min_elem=2*min_elem-y;
    }
    s.pop();
    
}

int MinStack::top() {
    if(s.empty())
        return -1;
    else if(min_elem>s.top())
        return min_elem;
    else
        return s.top();
}

int MinStack::getMin() {
     if(s.empty())
        return -1;
    else
        return min_elem;
}

