#include "mainlib.cpp"
#include <stack>

template<typename _T>
const _T as_const(_T val){
  return val;
};

calctree::calctree(){
  //l=r=nullptr;
  //l=r=NULL;
	//val=NULL;
}

calctree::calctree(const calctree& rsh){
  l=rsh.l;
  r=rsh.r;
  val=rsh.val;
};
calctree::calctree(const calctree&& rsh){
  l=rsh.l;
  r=rsh.r;
  val=rsh.val;
}

calctree::~calctree(){
  //delete l;
  //delete r;
  //delete this;
}


calctreeP build(vector<variant<int,char> > exp){
  stack<calctreeP> num;
  stack<calctreeP> opt;
	{
	  // calctree *p=new(calctree);
	  // 	p->val='(';
	  // 	opt.push(p);
	  // 	exp.push_back(')');
	  auto p=make_shared<calctree>();
	  p->val='(';
	  opt.push(p);
	  exp.push_back(')');
	}
	for(auto & i : exp){
		if(i.index()==0){
		  // calctree *p=new(calctree);
		  auto p=make_shared<calctree>();
			p->val=i;
			num.push(p);
		}else{
		  if(opt.empty()||level(get<char>(i))>=level(get<char>(opt.top()->val))){
		  // char optc=i;
		  // if(opt.empty()||level(optc)>=level(opt.top())){
		    // calctree *p=new(calctree);
		    auto p=make_shared<calctree>();
				p->val=i;
				opt.push(p);
			}else{
		    while(level(get<char>(opt.top()->val))>level(get<char>(i))){
					// calctree *optp=opt.top();opt.pop();
					// calctree *num1p=num.top();num.pop();
					// calctree *num2p=num.top();num.pop();
					// optp->l=num1p;
					// optp->r=num2p;
					// num.push(optp);
		      num.push(opt.top());
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
