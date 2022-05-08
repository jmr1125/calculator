#include "mainlib.cpp"
#include <stack>

calctree::calctree(){
	l=r=NULL;
	//val=NULL;
}
calctree::~calctree(){
	delete l;
	delete r;
	delete this;
}


calctree* build(vector<variant<int,char> > exp){
	stack<calctree*> num;
	stack<calctree*> opt;
	{
	  calctree *p=new(calctree);
		p->val='(';
		opt.push(p);
		exp.push_back(')');
	}
	for(auto & i : exp){
		if(i.index()==0){
		  calctree *p=new(calctree);
			p->val=i;
			num.push(p);
		}else{
		  if(opt.empty()||level(get<char>(i))>=level(get<char>(opt.top()->val))){
		  // char optc=i;
		  // if(opt.empty()||level(optc)>=level(opt.top())){
		    calctree *p=new(calctree);
				p->val=i;
				opt.push(p);
			}else{
		    while(level(get<char>(opt.top()->val))>level(get<char>(i))){
					calctree *optp=opt.top();opt.pop();
					calctree *num1p=num.top();num.pop();
					calctree *num2p=num.top();num.pop();
					optp->l=num1p;
					optp->r=num2p;
					num.push(optp);
				}
			}
		}
	}
	return num.top();
}
int level(char opt){
	if(opt=='(') return 0;
	if(opt=='+') return 1;
	if(opt=='-') return 1;
	if(opt=='*') return 2;
	if(opt=='/') return 2;
	if(opt==')') return -1;
	throw 0x7f;
}
