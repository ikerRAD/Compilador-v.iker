#ifndef EXP_HPP_
#define EXP_HPP_


struct expresionstruct {
  string str ;
  vector<int> trues ;
  vector<int> falses ;
};

struct sentenciastruct {
  vector<int> exit;
  vector<int> conti;
};

struct casestruct {
  vector<int> gotos;
  vector<int> exit;
  vector<int> conti;
  int ini;
};


#endif /* EXP_HPP_ */
