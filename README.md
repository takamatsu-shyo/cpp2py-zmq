# cpp2py-zmq
Take frames from a USB camera, send them via ZeroMQ to Python subscriber.

## 0. Setup environment
- Ubuntu 20.04
- Install OpenCV and `cppzmq` https://github.com/zeromq/cppzmq


## 1. Compile C++ code
```
cmake .
make
```

## 2. Prepare virtualenv for Python code
Open secondaly terminal
```
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```

## 3. Run C++ code (Publisher)
```
./Cpp2PyZmq
```

## 4. Run Python code (Subscriber)
At the secondaly  terminal.
```
python sub.py
```

## 5. Reference
https://stackoverflow.com/questions/55619871/how-to-i-transfer-an-imageopencv-matrix-numpy-array-from-c-publisher-to-pyth
