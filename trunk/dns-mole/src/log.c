/* log.c
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 2 as
 * published by the Free Software Foundation.  You may not use, modify or
 * distribute this program under any other version of the GNU General
 * Public License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *
 * $Id$
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void open_log(FILE **fp,char *name){

    time_t now = time(NULL);

    if((*fp = fopen(name,"a+")) == NULL){
            fprintf(stderr,"[fopen] Can't open log file\n"); 
            exit(EXIT_FAILURE);
    }

    fprintf(*fp,"[dns-mole] Log Started : %s", asctime(localtime(&now)));
}


void close_log(FILE **fp){

    time_t now = time(NULL);

    fprintf(*fp,"[dns-mole] Log Closed: %s", asctime(localtime(&now)));

    if(fclose(*fp)){
        fprintf(stderr,"[fclose] Can't close log file\n"); exit(EXIT_FAILURE);
    }
}

void write_log(FILE **fp,int type,char *msg){
    
    fprintf(*fp,"%d - %s\n",type,msg);
    fflush(*fp);
}

