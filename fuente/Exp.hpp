#ifndef EXP_HPP_
#define EXP_HPP_


struct expresionstruct {
  string str ;
  vector<int> trues ;
  vector<int> falses ;
  string tipo;
  int esVar;
};

struct sentenciastruct {
  vector<int> exit;
  vector<int> conti;
};

struct casestruct {
  vector<int> gotos;
  vector<int> exit;
  vector<int> conti;
  vector<string> tipes;
  int ini;
};

struct ctestruct {
  string str;
  string tipo;
};

struct lexprstruct {
  vector<string> exprs;
  vector<int> vars;
  vector<string> tipes;
};


#endif /* EXP_HPP_ */
