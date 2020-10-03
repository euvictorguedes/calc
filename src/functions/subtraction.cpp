#include <node.h>

using namespace v8;

void Subtraction(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  
  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, 
        "You need to pass 2 arguments or more")));

    return;
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, 
        "Wrong arguments")));

    return;
  }

  float subtraction = args[0].As<Number>()->Value();

  for (int i = 1; i < args.Length(); i++) {
    subtraction -= args[i].As<Number>()->Value();
  }

  Local<Number> result = Number::New(isolate, subtraction);

  args.GetReturnValue().Set(result);
}