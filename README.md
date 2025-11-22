# Simple linear regression from scratch.

Before testing both c++ and python implementations you need to run:
```
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

### To see c++ implementation run:

>
> Make sure you have **Conan** package manager installed
>

```
make install
make frun
```

#### Also you might need to change python version in cpp/main.cpp

```
// Fix Python path so it sees your .venv packages
PyRun_SimpleString("import sys");
//! change path to you actual enviroment
PyRun_SimpleString(
    "sys.path.insert(0, './.venv/lib/python --- here ------> 3.14 <------ here ---/site-packages')");
```


### To see python implementation run:

```
python3 python/main.py
```



