#define BUFFER_SIZE 10
typedef struct
{
	
} item; 

item buffer[BUFFER_SIZE];

int in = 0;
int out = 0; 

void prod(){
	item next_produced;
	while (true){
		while ((in+1) % BUFFER_SIZE ==out){
		}

		buffer[in]=next_produced;
		in = (in +1) %BUFFER_SIZE;
	}

}

void cons(){
item next_consumed;
	while (true) {
		while (in==out){
		}
		next_consumed=buffer[out];
		out=(out+1) % BUFFER_SIZE;

	}
}




