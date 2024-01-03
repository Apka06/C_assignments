struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};

void sortfb(int numofnodes, struct nodeFB **startFB){
	int nodecounter;
	int counter;
	int id_copy;
	int age_copy;
	struct nodeFB *current;
	struct nodeFB *nextnode;
	for(nodecounter = numofnodes-1; nodecounter >= 0; nodecounter--){
		current = *startFB;
		nextnode = current->next;
		for(counter = 0; counter <= nodecounter; counter++){
			if(current->id > nextnode->id){
				id_copy = current->id;
				current->id = nextnode->id;
				nextnode->id = id_copy;
				age_copy = current->age;
				current->age = nextnode->age;
				nextnode->age = age_copy;
			}
			current = nextnode;
			nextnode = current->next;
		}
	}
}


void sortgs(int numofnodes, struct nodeGS **startGS){
	int nodecounter;
	int counter;
	int id_copy;
	struct nodeGS *current;
	struct nodeGS *nextnode;
	for(nodecounter = numofnodes-1; nodecounter >= 0; nodecounter--){
		current = *startGS;
		nextnode = current->next;
		for(counter = 0; counter <= nodecounter; counter++){
			if(current->id < nextnode->id){
				id_copy = current->id;
				current->id = nextnode->id;
				nextnode->id = id_copy;
			}
			current = nextnode;
			nextnode = current->next;
		}
	}
}

void insertFB(struct nodeFB **startFB, int new_id, int new_age){
	struct nodeFB* ptr = NULL;
	struct nodeFB* newnode = (struct nodeFB*)malloc(sizeof(struct nodeFB));
	newnode -> id = new_id;
	newnode -> age = new_age;
	int numofnodes = 1;
	if (*startFB == NULL){
		*startFB = newnode;
	}
	else{
		ptr = *startFB;
		while(ptr->next != NULL){
			ptr = ptr->next;
			numofnodes ++;
		}
		ptr->next = newnode;
		sortfb(numofnodes, startFB);
	}
}

void insertGS(struct nodeGS **startGS, int new_id){
	struct nodeGS* ptr = NULL; 
	struct nodeGS* newnode = (struct nodeGS*)malloc(sizeof(struct nodeGS));
	newnode -> id = new_id;
	int numofnodes = 1;
	if (*startGS == NULL){
		*startGS = newnode;
	}
	else{
		ptr = *startGS;
		while(ptr->next != NULL){
			ptr = ptr->next;
			numofnodes ++;
		}
		ptr->next = newnode;
		sortgs(numofnodes, startGS);
	}
}


void printFB(struct nodeFB *startFB){
	struct nodeFB* ptr = NULL;
	ptr = startFB;
	while(ptr->next != NULL){
		printf("%d %d\n", ptr->id, ptr->age);
		ptr = ptr->next;
	}
	printf("%d %d\n\n", ptr->id, ptr->age);
}

void printGS(struct nodeGS *startGS){
	struct nodeGS* ptr = NULL;
	ptr = startGS;
	while(ptr->next != NULL){
		printf("%d\n", ptr->id);
		ptr = ptr->next;
	}
	printf("%d\n\n", ptr->id);
}


void insertFinalFB(struct newNodeFB **startNewFB, int new_id, int new_age){
	struct newNodeFB* ptr = NULL;
	struct newNodeFB* newnode = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
	newnode -> id = new_id;
	newnode -> age = new_age;
	if (*startNewFB == NULL){
		*startNewFB = newnode;
	}
	else{
		ptr = *startNewFB;
		while(ptr->next->next != NULL){
			ptr = ptr->next->next;
		}
		ptr->next->next = newnode;
	}
}

void insertFinalGS(struct newNodeFB **startNewFB, int new_id){
	struct newNodeFB* ptr = NULL; 
	struct newNodeGS* ptrck = NULL;
	struct newNodeGS* newnode = (struct newNodeGS*)malloc(sizeof(struct newNodeGS));
	newnode -> id = new_id;
	ptr = *startNewFB;
	while(ptr->next != NULL){
			ptrck = ptr->next;
			ptr = ptrck->next;
		}
		ptr->next = newnode;
}

void createFinalList(struct newNodeFB **startNewFB,struct nodeFB *startFB,struct nodeGS *startGS){
	struct newNodeGS *newGSnode = (struct newNodeGS*)malloc(sizeof(struct newNodeGS));
	struct newNodeFB *newFBnode = (struct newNodeFB*)malloc(sizeof(struct newNodeFB));
	struct nodeFB*fb_iterator = startFB;
	struct nodeGS*gs_iterator = startGS;
	while(fb_iterator -> next != NULL){
	insertFinalFB(startNewFB, fb_iterator->id,fb_iterator->age);
	insertFinalGS(startNewFB, gs_iterator->id);
	fb_iterator = fb_iterator->next;
	gs_iterator = gs_iterator->next;
	}
	insertFinalFB(startNewFB, fb_iterator->id,fb_iterator->age);
	insertFinalGS(startNewFB, gs_iterator->id);
}

void printAll(struct newNodeFB *startNewFB){
	struct newNodeFB* ptrfb = NULL;
	struct newNodeGS* ptrgs = NULL;
	ptrfb = startNewFB;
	ptrgs = ptrfb->next;
	while(ptrgs->next!=NULL){
	printf("%d %d\n", ptrfb->id, ptrfb->age);
	printf("%d\n", ptrgs->id);
	ptrfb = ptrgs->next;
	ptrgs = ptrfb->next;
	}
	printf("%d %d\n", ptrfb->id, ptrfb->age);
	printf("%d\n", ptrgs->id);
}

// You must write all the function definitions to be used in this lab into this file. 
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.