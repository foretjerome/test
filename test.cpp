#include <iostream>

template<class Super>
struct Layer : public Super
{
  struct Foo : public Super::Foo
  {
    void f(){
      (*Super::Foo)this->f();
    }
  };
};

struct Assembly{
  struct Foo
  {
    void f(){
       std::cout << "Hello mixin" << std::endl;
    }
  }
   
  typedef Layer<Assembly>;
};

int main(){
   Assembly::Foo a;
   a.f();
   return 0;
}
