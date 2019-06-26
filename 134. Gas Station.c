int conv(int i, int size){
    if(i<size)
        return i;
    else
        return i%size;
}

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    
    //assume gasSize == codtSize!
    int stationSize = gasSize;
    for(int start =0; start < stationSize; start++){
        int tank = 0;
        for(int station=0; station < stationSize; station++){
            //fill tank
            tank += gas[conv(start+station, stationSize)];
            
            //consume cost
            tank -= cost[conv(start+station, stationSize)];
            
            //fail, no need to continue
            if(tank < 0)
                break;
        }
        
        if(tank >=0){
            //found
            return start;
        }
        
    }
    return -1;

}

