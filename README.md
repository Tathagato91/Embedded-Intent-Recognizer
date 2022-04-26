# Intent Recognition Command line tool

The input and expected output looks like this:

```
What is the weather like today? => Prints (Intent: Get Weather)
What is the weather like in Paris today? => Prints (Intent: Get Weather City)
Tell me an interesting fact. => Prints (Intent: Get Fact)
```

## Build instruction
1. Go to top level directory `Embedded-Intent-Recognizer`
2. Check if build directory exists or not, if exists remove it by `rm -rf build`
3. Execute `mkdir build && cd build && cmake .. && make`


## Execution instruction
`./EmbeddedIntentRecognizer <user input to know the intent>`

**NOTE:** Punctuations at the end should be given with a escape character. Check this [StackOverFlow page](https://stackoverflow.com/questions/56028459/passing-punctuaton-marks-through-command-line-in-c).


###### Example inputs

1. `./EmbeddedIntentRecognizer What is the weather like today`

Output -
```
Intent: Get Weather Time
```

2. `./EmbeddedIntentRecognizer What is the weather like in Paris today`

Output -
```
Intent: Get Weather City Time
```


3. `./EmbeddedIntentRecognizer Tell me an interesting fact`

Output -
```
Intent: Get Fact
```


4. `./EmbeddedIntentRecognizer What is the weather prediction at 1:30AM at Tokyo`

Output -
```
Intent: Get Weather City Time
```


5. `./EmbeddedIntentRecognizer book doctor visit at 11:30PM`

Output -
```
Intent: Get Appointment
```

6. `./EmbeddedIntentRecognizer where Berlin is`

Output -
```
Intent: Get Fact
```


7. `./EmbeddedIntentRecognizer how to make cookies`

Outout -
```
Intent: Get Fact
```


8. `./EmbeddedIntentRecognizer how costly Berlin is`

Outout -
```
Intent: Get Fact
```


9. `./EmbeddedIntentRecognizer Should we expect a thunderstorm at Berlin tomorrow`

Outout -
```
Intent: Get Fact
```

10. `./EmbeddedIntentRecognizer Should we expect a thunderstorm at Berlin tomorrow`

Output -
```
Intent: Get Weather City Time
```
