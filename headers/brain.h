void help(){
	printf("\33[1;31m\t      -----Controls-----\n");
	printf("    ^         k for up\n");
	printf("    k         l for right\n");
	printf("<j  O  l>     j for left\n");
	printf("    m         m for down\n");
	printf("    -                     \n");
	printf("              <SPACE> to place your move\n");
	printf("              1 to exit\n\n\33[1;0m");
}

int win(){
        unsigned short int y, w , countx=0, county = 0, ccx = 0, ccy = 0;
        for(y = 2;y < 12; y+= 4){
        	for(w = 0;showy[w] != 0; w+=2){
			if(showy[w] == y){
				county++;
			}
			if(showx[w] == y+1){
				countx++;
			}
			if(showy[w] == y && showx[w] == y+1){
				ccx++;
			}
			if((showx[w] + showy[w]) == 13){
				ccy++;
			}
	//The following line is for debugging
	//printf("P1 -> countx = %d, county = %d, ccx = %d, ccy = %d\n", countx, county, ccx, ccy);
		}
		if(countx >= 3 || county >= 3 || ccx >= 3 || ccy >= 3){
			return 1;
        	}
		countx = 0; county = 0; ccy = 0;
	}
	ccx = 0;
	for(y = 2;y < 12; y+= 4){
                for(w = 1;showy[w] != 0; w+=2){
                        if(showy[w] == y){
                                county++;
                        }
                        if(showx[w] == y+1){
                                countx++;                                                             }
                        if(showy[w] == y && showx[w] == y+1){
                                ccx++;
                        }
                        if((showx[w] + showy[w]) == 13){
                                ccy++;
                        }
	//The following line is for debugging
        // printf("P2 -> countx = %d, county = %d, ccx = %d, ccy = %d\n", countx, county, ccx, ccy);
                }
                if(countx >= 3 || county >= 3 || ccx >= 3 || ccy >= 3){ 
			return 2; 
		}
                countx = 0; county = 0; ccy = 0;
	}
	if(showx[8] != 0){
		return 3;
	}
	return 0;
}

int dif(int x, int y){
    int i;
    for(i=0;showx[i] != 0;i++){
        if(x == showx[i] && y == showy[i]){
            return 1;
        }
    }
    return 0;
}
