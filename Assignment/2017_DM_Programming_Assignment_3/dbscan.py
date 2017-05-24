import sys

def getDist(point1, point2):
    # Get the distance between the two points.
    # Casting from string to float to calculate
    x1 = float(point1[1])
    x2 = float(point2[1])
    y1 = float(point1[2])
    y2 = float(point2[2])
    return pow((pow(x1 - x2, 2) + pow(y1 - y2, 2)), 0.5)

def regionQuery(P, Eps, DataSet):
    neighborhood = []                   #make neighborhood list
    for point in DataSet:              #Search all point in DataSet
        if getDist(P, point) < Eps:     #if the distance between P and Point is less than Epsilon
            neighborhood.append(point)  #P and point are neighborhood
    return neighborhood                 #Returns the neighborhood set of P

def expandCluster(P, neighborhood, C, cNum, Eps, MinPts, DataSet, visited):
    C[cNum].append(P)                   #Append Point P to cNum cluster.
    for point in neighborhood:          #The set of neighbors of Point P
        if point not in visited:        #if point is not visited
            visited.append(point)       #mark point as visited
            neighborhood_temp = regionQuery(point, Eps, DataSet)    #Find neighborhood of point
            if len(neighborhood_temp) >= MinPts:                    #if the number of point's neighborhood is greater than MinPts
                neighborhood += neighborhood_temp                   #point's neighborhood joined with P's neighborhood.
        if point not in C[cNum]:                                   #if point is not in cNum Cluster
            C[cNum].append(point)                                   #Append point to cNum Cluster

def DBSCAN(DataSet, n, Eps, MinPts, inputFileName):
    C = []              #declare Cluster List
    cNum = -1           #declare Cluster Num
    visited = []        #decalre visit List

    for point in DataSet:           #for each point in dataset
        if point not in visited:    #if point is not visited
            visited.append(point)    #mark point as visited
            neighborhood = regionQuery(point, Eps, DataSet) #get neighborhood list of point
            if len(neighborhood) >= MinPts: #if the number of neighbors is greater than the MinPts value
                C.append([]) #make new Cluster
                cNum += 1    #Increase number of Cluster
                expandCluster(point, neighborhood, C, cNum, Eps, MinPts, DataSet, visited) #Start cluster expansion from point.

    sorted(C, key = len) #Sort the cluster list based on the length of each cluster.
    indexOfInputFile = inputFileName[5] #Get the fifth character of input file name for the output file name.
    for i in range(n): #Make only n clusters.
        fout = open("input" + indexOfInputFile + "_cluster_" + str(i) + ".txt", 'w') #output text file create
        for point in C[i]: #In each cluster,
            fout.write(point[0] + '\n') #Read and input the object_id value.
        fout.close() #output text file close

def main(inputFileName, n, Eps, MinPts):
    fr = open(inputFileName)                                             #Open input text file to DBSCAN
    DataSet = [inst.strip().split('\t') for inst in fr.readlines()]     #Read the input txt file and put it into an list called DataSet
    DBSCAN(DataSet, int(n), int(Eps), int(MinPts), inputFileName)        #Do DBSCAN using argument
    fr.close()                                                           #Close input text file

if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])