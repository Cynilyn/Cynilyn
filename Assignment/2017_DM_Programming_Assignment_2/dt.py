import operator
import sys
from math import log
from functools import reduce  # forward compatibility for Python 3

def ClassCnt(classList):    #Count how many times it has appeared in the training data set for each class type.
    global totalCount
    totalCount = {}
    for vote in classList:  #Search for a classList that contains only class values.
        if vote not in totalCount.keys(): totalCount[vote] = 0    #Add class type if it does not exist.
        totalCount[vote] += 1  #If it already exists, add a count value of 1.

def calcEnt(dataSet): #Calculates the info value for the input data set.
    numEnties = len(dataSet) #get the total number of data
    labelCounts = {}        #declare a variable of dictionary type
    for featVec in dataSet:                        #read data set line by line
        currentLabel = featVec[-1]                  #get the class value
        if currentLabel not in labelCounts.keys(): #if the class value is not a dicionary key
            labelCounts[currentLabel] = 0           #create a new key
        labelCounts[currentLabel] += 1              #if key is exist, increments value by 1
    entropy = 0.0    #the variable to store the entropy
    #after passing through the for loop, the number of class values is determined for each type.
    for key in labelCounts: # Calculate the probability and get entropy for each class
        prob = float(labelCounts[key]) / numEnties #'get the probability
        entropy -= prob * log(prob, 2) #get the entropy
    return entropy  #return entropy

def splitDataSet(dataSet, n, value): #in the data set, extract data whose the nth attribute matches value.
    retDataSet = []
    for featVec in dataSet:
        if featVec[n] == value: #if the nth attribute is equal to value
            reducedFeatVec = featVec[:n] #before nth
            reducedFeatVec.extend(featVec[n + 1:]) #after (n+1)th
            retDataSet.append(reducedFeatVec) #append the processed data.
    return retDataSet #return the data set from which the nth attribute was extracted

def chooseBestFeatureToSplit(dataSet): #select the best attribute for data partitioning.
    numFeatures = len(dataSet[0]) - 1 #the last is the class value, so exclude it.
    baseEntropy = calcEnt(dataSet) #calculate Info(D)
    bestGainRatio = 0.0; bestFeature = -1 #initialize
    for i in range(numFeatures): #Traverse the attributes of the dataSet to find out which Attribute is best.
        featList = [example[i] for example in dataSet]  #only the corresponding values are extracted
        uniqueVals = set(featList) #create a list with no duplicates
        newEntropy = 0.0 #for Info_A(D)
        splitInfo = 0.0  #for SplitInfo_A(D)
        for value in uniqueVals:
            subDataSet = splitDataSet(dataSet, i, value) #A set of data having the corresponding value in the corresponding attribute
            prob = len(subDataSet) / float(len(dataSet)) #get the probability
            newEntropy += prob * calcEnt(subDataSet) #get the entropy for attribute, info_A(D)
            splitInfo -= prob * log(prob, 2) #get the Splitinfo_A(D)
        infoGain = baseEntropy - newEntropy #calculate Gain(A)
        gainRatio = infoGain / splitInfo #calculate GainRatio(A) = Gain(A) / Splitinfo_A(D)
        if(gainRatio > bestGainRatio): #if the gainRatio is higher than bestGainRatio, it updates with correspoding information.
            bestGainRatio = gainRatio #update bestGainRatio
            bestFeature = i #update best index
    return bestFeature # return best index

def createTree(dataSet, labels):
    classList = [example[-1] for example in dataSet] #gathers the last argument of the dataSet and put into the classList.
    if classList.count(classList[0]) == len(classList): #If all data sets are of the same class value
        return classList[0]                             #it has reached the leaf.
    bestFeat = chooseBestFeatureToSplit(dataSet)    #return attribute index is best to split in the current dataSet.
    bestFeatLabel = labels[bestFeat]                #get the label of the best feat.
    myTree = {bestFeatLabel: {}}                    #create a tree using the dictionary type.
    del (labels[bestFeat])                          #remove labels[bestFeat] to prevent duplication.
    featValues = [example[bestFeat] for example in dataSet] #bring only the value corresponding to the bestFeat
    uniqueVals = set(featValues)    #use 'set' to remove the duplicate.
    for value in uniqueVals:
        subLabels = labels[:] #copy label
        #Splits the dataSet based on bestFeat and recurses into createTree with subLabels
        #The return value is filled in myTree to complete the decision tree.
        myTree[bestFeatLabel][value] = createTree(splitDataSet(dataSet, bestFeat, value), subLabels)
    return myTree

def makeDecisionTree(dt_train):
    global classLabel   #variables to contain classLabel. ex) buys_computer, car_evaluation
    global dataSetTree  #variables to contain decision tree

    fr = open(dt_train) #open the training file to make decision tree
    dataSetLabel = fr.readline().strip().split('\t')    #read the first line and divide the line by '\t'
    classLabel = dataSetLabel.pop() #it contains a '\n' as the final argument, so it pops.
    dataSet = [inst.strip().split('\t') for inst in fr.readlines()] #read rest of all and put it into an array called dataSet.

    classList = [example[-1] for example in dataSet] #gathers the last argument of the dataSet and put into the classList.

    ClassCnt(classList) #count how many times it has appeared in the training data set for each class type.
                        #determine which class values are more frequent.

    dataSetTree = createTree(dataSet, dataSetLabel) #create a Tree using the dataSet and dataSetLabel obtained above.
    fr.close()  #clos the training file

def getFromDict(dataDict, mapList):     #in a tree of a dictionary type, it returns subtree after passing map list
    return reduce(operator.getitem, mapList, dataDict)

def decideClassValue(value, dataSetTree, dataSetLabel):
     if isinstance(dataSetTree, str): #if dataSetTree is string type, it means that dataSetTree is a leaf node.
         #There is data that can not be processed when following a decision tree.
         #For example, the door value is 3, and the decision tree gives a value of 2 or 4.
         #In this case, we use class values of 2 and 4 or class values of 2 and 4 subtrees.
         # Set the class value of 3 to the most common class value.
         #To do this, we store the class value frequency of sibling nodes in the 'subCount' array.
         #If the class values of siblings are all the same, take the highest frequency in the entire decision tree.
         #To do this, 'makeDecisionTree' calculates the total class value frequency through 'ClassCnt' and stores it in 'totalCount'.
        if dataSetTree not in subCount.keys(): subCount[dataSetTree] = 0
        subCount[dataSetTree] += 1
        return dataSetTree

     index = dataSetLabel.index(dataSetTree.keys()[0]) #identify the index of the first decision maker of current decision tree
     next = [dataSetTree.keys()[0], value[index]]   #The attribute and its value are stored in 'next' array.
     if(value[index] in dataSetTree.values()[0]):
         #If there is a path for value and the subtree of the current decision tree can be searched
         #it means we can follow the decision tree normally,
         #recursively search the decision tree
         return decideClassValue(value, getFromDict(dataSetTree, next), dataSetLabel)
     else:
         #Abnormal case first mentioned in decideClassValue
         subCount.clear()   #Now we need to check the class value frequency of the sibling nodes and clear it.
         for substitute in dataSetTree.values()[0].keys(): #explore sibling nodes
             next = [dataSetTree.keys()[0], substitute] #Use the class value of the sibling node instead.
             decideClassValue(value, getFromDict(dataSetTree, next), dataSetLabel) #Recursive search through sibling nodes
         bestIndex = 0
         bestCount = 0
         #Since the subCount array is complete, it starts computation.
         for i in range(len(subCount.values())):
             if subCount.values()[i] > bestCount: #If there is a class value with a higher frequency, update
                 bestIndex = i
                 bestCount = subCount.values()[i]
             elif subCount.values()[i] == bestCount:
                 #If there is a class value with the same frequency,
                 #consider the frequency in the entire decision tree.
                if totalCount[subCount.keys()[i]] > totalCount[subCount.keys()[bestIndex]]:
                    bestIndex = i
                    bestCount = subCount.values()[i]
         return subCount.keys()[bestIndex] #return the guessed value through calculation.

def makeOutputFromTest(dt_test, fout):
    fr = open(dt_test)   #open file for testing
    global subCount        #count how many of each class value exists.

    dataSetLabel = fr.readline() #read data set label on the first line
    dataSetLabel = dataSetLabel[:-1] + '\t' + classLabel + '\n' #remove the new line charachter('\n') and attach the class label
    fout.write(dataSetLabel) #write the label to the output file
    dataSetLabel = dataSetLabel.strip().split('\t') #split dataSetLabel into '\t', keep label values as an array.
    subCount = {}  #declare it as dictionary type

    for inst in fr.readlines():
        inst = inst[:-1]    #remove the new line character
        dataSet = inst.split('\t')  #split it into '\t'
        output = decideClassValue(dataSet, dataSetTree, dataSetLabel) #determine class value for each data and return to ouput
        fout.write(inst + '\t' + output + '\n') #write output to the output file
    fr.close()

def main(trainFileName, testFileName, resultFileName):
    fout = open(resultFileName, 'w') #open the file to save result
    makeDecisionTree(trainFileName) #make decision tree
    makeOutputFromTest(testFileName, fout) #make output file from test file and decision tree
    fout.close()

if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2], sys.argv[3]) # receives a filename for training, testing and printing result.
