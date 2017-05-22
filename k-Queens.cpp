#include<iostream>
#include<cstdlib>
#include<time.h>
#define Amount 8


using namespace std;

class Unit{
public:
	int serial;
	int position[2];
	int conflict;
};

void Display( int kkk[][Amount] ){
	int n = Amount;
	int i,j;
	for ( i=0;i<n;i++ ){
		for ( j=0;j<n;j++ ){
			//kkk[i][j] = 0;
			cout << kkk[i][j];
		}
		cout << endl;
	}
}
//­pºâ½Ä¬ð
Unit Queens[Amount];
int CalConflict( Unit k, int arr[][Amount] ){
	int x,y;
	int i,j;
	int b;
	int conflict = 0;
	x = k.position[0];
	y = k.position[1];
	//cout << x << " " << y << endl;
	for ( i=0;i<Amount;i++ ){
		if ( arr[i][y] == 1 )
			conflict++;
	}
	for ( j=0;j<Amount;j++ ){
		if ( arr[x][j] == 1 )
			conflict++;
	}
	//cout << conflict <<"hi"<< endl;
	//cout << conflict <<endl;
	// y=ax+b
	b = y-x;
	if ( x>y ){
		i = x-y;
		j = 0;
		for ( ;i<Amount,j<Amount;i++,j++ ){
			if ( arr[i][j] == 1 )
				conflict++;
		}
	}
	else if ( x == y ){
		for ( i=0,j=0;i<Amount,j<Amount;i++,j++ )
			if ( arr[i][j] == 1 )
				conflict++;
	}
	else if ( x<y ){
		i = 0;
		j = x-b;
		for ( ;i<Amount,j<Amount;i++,j++ ){
			if ( arr[i][j] == 1 )
				conflict++;
		}
	}
	//cout << conflict <<endl;
	b = x + y;
	if ( b < (Amount - 1) ){
		i = 0;
		j = b;
		//cout << j << endl;
		for ( ;i<Amount,j>=0;i++,j-- ){
			if ( arr[i][j] == 1 )
				conflict++;
		}
	}
	else if ( b == (Amount - 1) ){
		i = 0;
		j = b;
		for ( ;i<Amount,j>=0;i++,j-- ){
			if ( arr[i][j] == 1 )
				conflict++;
		}
	}
	else if ( b> (Amount - 1) ){
		i = y-b;
		j = Amount -1 ;
		for ( ;i<Amount,j>=0;i++,j-- ){
			if ( arr[i][j] == 1 )
				conflict++;
		}
	}
	//cout << conflict <<endl;
	cout << x << " " << y << endl;
	cout << conflict-4 << endl;

	return conflict -4 ;
}

int All_Conflict( Unit k, int arr[][Amount] ){
	int conflict = 0;
	int i;
	for ( i=0;i<Amount;i++ ){
		if ( k.serial == i )
			conflict+= CalConflict( k,arr );
		else
			conflict += CalConflict( Queens[i],arr );

		cout << conflict << endl;
	}

	return conflict;
}

int main(void){
	int i,j,k;
	int Puzzle[Amount][Amount];

	Unit now,next,temp;

	unsigned seed;
	seed = (unsigned)time(NULL);
	srand(seed);
	//Âk¹s
	for( j=0;j<Amount;j++ ){
		for ( i=0;i<Amount;i++ ){
			Puzzle[i][j] = 0;

		}
		for ( i=0;i<Amount;i++ ){
			Queens[i].position[0] = i;
			Queens[i].position[1] = 3;
			Puzzle[ Queens[i].position[0] ][ Queens[i].position[1] ] = 1;
		}
		/*
		Queens[j].position[0] = rand()%8;
		Queens[j].position[1] = j;
		Queens[j].serial = j;
		//cout << Queens[i].position[1] << endl;*/


	}
	now = Queens[0];
	now.conflict = All_Conflict( now, Puzzle );
	next = now;
	cout << now.conflict << endl;
	Display(Puzzle);
	/*while ( now.conflict != 0 ){
		for ( i=0;i<Amount;i++ ){
			for ( j=0;j<Amount;j++ ){
				if( j==Queens[i].position[0] )
					continue;
				temp.position[0] = j;
				temp.position[1] = Queens[i].position[1];
				temp.conflict = All_Conflict( temp,Puzzle );
				temp.serial = Queens[i].serial;
				if ( temp.conflict < next.conflict )
					next = temp;
			}
		}
		if ( now.conflict < next.conflict ){
			Puzzle[now.position[0]][now.position[1]] = 0;
			Puzzle[next.position[0]][next.position[1]] = 1;
			now = next;
		}
		else{
			for( j=0;j<Amount;j++ ){
				for ( i=0;i<Amount;i++ )
					Puzzle[i][j] = 0;
				Queens[j].position[0] = rand()%8;
				Queens[j].position[1] = j;
				Queens[j].serial = j;
				//cout << Queens[i].position[1] << endl;
				Puzzle[ Queens[j].position[0] ][ Queens[j].position[1] ] = 1;
			}
			now = Queens[0];
			now.conflict = All_Conflict( now, Puzzle );
			next = now;
			cout << now.conflict << endl;
		}
	}

	Display(Puzzle);*/
}

