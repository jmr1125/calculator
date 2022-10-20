#include "mainlib.cpp"

int calcval::getv(){
  return v;
}
string calcval::getstr(){
  return to_string(v);
}
calcval::~calcval(){
}

int calcneg::getv(){
  return -v;
}
string calcneg::getstr(){
  return "-"+v->getstr();
}
calcneg::~calcval(){
  delete v;
}

int calcbin::getv(){
  if(op=='+'){return l->getv()+r->getv();}
  if(op=='-'){return l->getv()-r->getv();}
  if(op=='*'){return l->getv()*r->getv();}
  if(op=='/'){return l->getv()/r->getv();}
}
string calcbin::getstr(){
  string ans="";
  if(level(l->op)<level(this->op)){
    ans+="(";
  }
  ans+=l->getstr();
  if(level(l->op)<level(this->op)){
    ans+=")";
  }
  ans+=op;
  if(level(r->op)<level(this->op)){
    ans+="(";
  }
  ans+=r->getstr();
  if(level(r->op)<level(this->op)){
    ans+=")";
  }
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
