#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#define ll long long
#define MAX_INT (2147483647)
#define MIN_INT (-2147483648)
using namespace std;
typedef pair<int, int> ii; typedef vector<ii> vii;
typedef vector<int> vi;

struct position{
    int x;
    int y;
};

struct warehouse{
    int id;
    position coordinates;
    vi max_capacity;
    vi disponible;
    vii distanceToOrders;
};

struct order{
    int id;
    position coordinates;
    vi items_needed;
    vii distanceToWarehouses;
};

struct drone{
    int id;
    position coordinates;
    int timeRemaining;
    int nextOfferEnd;
    vii distanceToWarehouses;
    vii distanceToOrders;
};

int nbDrones;
int nbTurns;
int nbWarehouses;
int nbOrders;
int max_weightDrone;
int nbTypes;
int sizeX,sizeY;
vi typeWeight;
vector<warehouse> warehouses;
vector<order> orders;
vector<drone> drones;
vector<bool> order_done;
vector<vector<pair<int,pair<int,int> > > > best_delivery; // vector->(order->warehouse,<type,nb>)
ofstream output("output1.out");
ifstream input("input1.in");
vector<string> file_output;
vector<int> order_best_delivery;

template <typename T>
      string NumberToString ( T Number )
      {
         ostringstream ss;
         ss << Number;
         return ss.str();
      }

int calcul_distance_grid(position a, position b){
    double tmp1=pow(a.x-b.x,2);
    double tmp2=pow(a.y-b.y,2);
    double res=sqrt(tmp1+tmp2);
    return (int)ceil(res);
}

bool verif_order_done(order O){
    for(int i=0;i<O.items_needed.size();i++)
        if(O.items_needed[i]!=0)
            return false;
    order_done[O.id]=true;
    return true;
}

void calcul_distances_WO(){
    for(int i=0;i<nbWarehouses;i++){
        for(int j=0;j<nbOrders;j++){
            warehouses[i].distanceToOrders[j]=ii(orders[j].id,calcul_distance_grid(warehouses[i].coordinates,orders[j].coordinates));
            orders[j].distanceToWarehouses[i]=ii(warehouses[i].id,calcul_distance_grid(warehouses[i].coordinates,orders[j].coordinates));
        }
    }
}

void calcul_distances_drones(){
    for(int k=0;k<nbDrones;k++){
        for(int i=0;i<nbWarehouses;i++){
            for(int j=0;j<nbOrders;j++){
                drones[k].distanceToOrders[j]=ii(orders[j].id,calcul_distance_grid(warehouses[i].coordinates,orders[j].coordinates));
                drones[k].distanceToWarehouses[i]=ii(warehouses[i].id,calcul_distance_grid(warehouses[i].coordinates,orders[j].coordinates));
            }
        }
    }
}

bool compare_pair_ii_second_inc(ii A,ii B){
    return (A.second<B.second);
}

bool compare_pair_iii_first_inc(pair<int,pair<int,int> > A, pair<int,pair<int,int> > B){
    return (A.first<B.first);
}

void sort_distance_drones(){
    for(int i=0;i<nbDrones;i++){
        sort(drones[i].distanceToWarehouses.begin(),drones[i].distanceToWarehouses.end(),compare_pair_ii_second_inc);
        sort(drones[i].distanceToOrders.begin(),drones[i].distanceToOrders.end(),compare_pair_ii_second_inc);
    }
}

void sort_distance(){
    for(int i=0;i<nbOrders;i++){
        sort(orders[i].distanceToWarehouses.begin(),orders[i].distanceToWarehouses.end(),compare_pair_ii_second_inc);
    }
    for(int i=0;i<nbWarehouses;i++){
        sort(warehouses[i].distanceToOrders.begin(),warehouses[i].distanceToOrders.end(),compare_pair_ii_second_inc);
    }
    sort_distance_drones();
}

int search_distance_drone_warehouse(drone D,int W_id){
    for(int i=0;i<D.distanceToWarehouses.size();i++){
        if(D.distanceToWarehouses[i].first==W_id)
            return D.distanceToWarehouses[i].second;
    }
}

bool exists_in_order_best_delivery(int x){
    for(int i=0;i<order_best_delivery.size();i++){
        if(x==order_best_delivery[i])
            return true;
    }
    return false;
}

void sort_best_delivery_WO(){
    for(int i=0;i<best_delivery.size();i++){
        sort(best_delivery[i].begin(),best_delivery[i].end(),compare_pair_iii_first_inc);
    }
}

int find_ind_best_order_delivery(){
    int ind_min=-1,dist=999999,tmp_dist=-1,w;
    for(int i=0;i<best_delivery.size();i++){
        if(!order_done[i]){
            tmp_dist=-1;
            for(int j=0;j<best_delivery[i].size();j++){
                w=best_delivery[i][j].first;
                for(int k=0;k<orders[i].distanceToWarehouses.size();k++){
                    if(w==orders[i].distanceToWarehouses[k].first){
                        tmp_dist=max(tmp_dist,orders[i].distanceToWarehouses[k].second);
                        break;
                    }
                }
                //cout << "tmp_dist: " << tmp_dist << "\n";
            }
            if(dist>tmp_dist){
                //cout << "dist: " << dist << "\n";
                dist=tmp_dist;
                ind_min=i;
            }
        }
    }
    return ind_min;
}

void sort_best_delivery_distance_WO(){
    int min_dist;
    int tmp_dist;
    int ind_order_min;
    int last_warehouse=-1,count_warehouses=0;
    //vector<int> tmp_order_done;
    order_best_delivery.clear();
    for(int i=0;i<best_delivery.size();i++){
        min_dist=999999;
        tmp_dist=-1;
        ind_order_min=-1;
        for(int j=0;j<best_delivery.size();j++){
            if(!exists_in_order_best_delivery(j) && !order_done[j]){
                last_warehouse=-1,count_warehouses=0;
                for(int k=0;k<best_delivery[j].size();k++){
                    if(last_warehouse!=best_delivery[j][k].first){
                        tmp_dist=max(tmp_dist,calcul_distance_grid(orders[j].coordinates,warehouses[best_delivery[j][k].first].coordinates));
                        //count_warehouses++;
                        last_warehouse=best_delivery[j][k].first;
                    }
                }
                //tmp_dist/=count_warehouses;
                if(tmp_dist<min_dist){
                    min_dist=tmp_dist;
                    ind_order_min=j;
                }
            }
        }
        if(ind_order_min!=-1){
            order_best_delivery.push_back(ind_order_min);
        }
        else
            break;
    }
    /*for(int i=0;i<order_best_delivery.size();i++){
        tmp_order_done.push_back(order_best_delivery[i]);
    }
    order_best_delivery.clear();
    for(int i=0;i<tmp_order_done.size();i++){
        order_best_delivery.push_back(tmp_order_done[i]);
    }*/
}

void calcul_best_delivery_WO(){
    best_delivery.clear();
    for(int i=0;i<nbOrders;i++){
        //if(!verif_order_done(orders[i])){
            vector<pair<int,pair<int,int> > > V;
            for(int j=0;j<nbTypes;j++){
                if(orders[i].items_needed[j]!=0){
                    int item_type=j;
                    int quantity_needed=orders[i].items_needed[j];
                    for(int k=0;k<nbWarehouses;k++){
                        int closest_warehouse=orders[i].distanceToWarehouses[k].first;
                        int quantity_dispo_in_warehouse=warehouses[closest_warehouse].disponible[item_type];
                        if(quantity_dispo_in_warehouse>=quantity_needed){
                            V.push_back(pair<int,pair<int,int> >(warehouses[closest_warehouse].id,ii(item_type,quantity_needed)));
                            break;
                        }
                        else if(quantity_dispo_in_warehouse!=0){
                            V.push_back(pair<int,pair<int,int> >(warehouses[closest_warehouse].id,ii(item_type,quantity_dispo_in_warehouse)));
                            quantity_needed-=quantity_dispo_in_warehouse;
                        }
                    }
                }
            }
            best_delivery.push_back(V);
        //}
    }
    sort_best_delivery_WO();
}

void calcul_best_delivery_drones(){

}

int calcul_nextOfferEnd_min(){
    int minO=999999;
    for(int i=0;i<nbDrones;i++){
        if(drones[i].nextOfferEnd<minO)
            minO=drones[i].nextOfferEnd;
    }
    return minO;
}

void load_function(drone* D, warehouse* W, int type, int quantity){
    cout << "load" << endl;
    D->timeRemaining-=1+calcul_distance_grid(D->coordinates, W->coordinates);
    D->nextOfferEnd+=1+calcul_distance_grid(D->coordinates, W->coordinates);
    position p;
    p.x=W->coordinates.x;
    p.y=W->coordinates.y;
    D->coordinates=p;
    W->disponible[type]-=quantity;
    file_output.push_back(NumberToString(D->id)+" L "+NumberToString(W->id)+" "+NumberToString(type)+" "+NumberToString(quantity)+"\n");
    output << file_output[file_output.size()-1];
    calcul_distances_drones();
    sort_distance_drones();
}

void unload_function(drone* D, warehouse* W, int type, int quantity){
}

void wait_function(drone *D,int time){
}

bool verif_all_order_done(){
    for(int i=0;i<nbOrders;i++){
        if(!verif_order_done(orders[i]))
            return false;
    }
    return true;
}

void deliver_function(drone* D, order* O, int type, int quantity){
    cout << "deliver" << endl;
    position p;
    p.x=O->coordinates.x;
    p.y=O->coordinates.y;
    O->items_needed[type]-=quantity;
    D->coordinates=p;
    D->timeRemaining-=1+calcul_distance_grid(D->coordinates, O->coordinates);
    D->nextOfferEnd+=1+calcul_distance_grid(D->coordinates, O->coordinates);
    file_output.push_back(NumberToString(D->id)+" D "+NumberToString(O->id)+" "+NumberToString(type)+" "+NumberToString(quantity)+"\n");
    output << file_output[file_output.size()-1];
    calcul_distances_drones();
    sort_distance_drones();
}

int main()
{

    int saisie,saisie2;
    input >> sizeX >> sizeY;
    input >> nbDrones >> nbTurns >> max_weightDrone;
    input >> nbTypes;
    for(int i=0;i<nbTypes;i++){
        input >> saisie;
        typeWeight.push_back(saisie);
    }

    /** Warehouse **/
    input >> nbWarehouses;
    for(int i=0;i<nbWarehouses;i++){
        warehouse W;
        W.id=i;
        input >> W.coordinates.x >> W.coordinates.y;
        for(int j=0;j<nbTypes;j++){
            input >> saisie;
            W.max_capacity.push_back(saisie);
            W.disponible.push_back(saisie);
        }
        //W.distanceToOrders.resize(nbOrders);
        warehouses.push_back(W);
    }

    /** Order **/
    input >> nbOrders;
    for(int i=0;i<nbWarehouses;i++)
        warehouses[i].distanceToOrders.resize(nbOrders);

    for(int i=0;i<nbOrders;i++){
        order_done.push_back(false);
        order O;
        O.id=i;
        input >> O.coordinates.x >> O.coordinates.y;
        O.items_needed.resize(nbTypes);
        O.distanceToWarehouses.resize(nbWarehouses);
        input >> saisie;
        for(int j=0;j<saisie;j++){
            input >> saisie2;
            O.items_needed[saisie2]++;
        }
        orders.push_back(O);
    }
    calcul_distances_WO();

    /** Drone **/
    for(int i=0;i<nbDrones;i++){
        drone D;
        D.coordinates.x=warehouses[0].coordinates.x;
        D.coordinates.y=warehouses[0].coordinates.y;
        D.timeRemaining=nbTurns;
        D.nextOfferEnd=0;
        D.distanceToWarehouses.resize(nbWarehouses);
        D.distanceToOrders.resize(nbOrders);
        D.id=i;
        drones.push_back(D);
    }

    calcul_distances_WO();
    calcul_distances_drones();
    sort_distance();
    calcul_best_delivery_WO();
    sort_best_delivery_WO();
    sort_best_delivery_distance_WO();
    int min_dist=999999,id_min=0,id_warehouse=best_delivery[0][0].first;
    //vector<vector<pair<int,pair<int,int> > > > best_delivery; // vector->(order->warehouse,<type,nb>)
    //used_drone.assign(sizeof(bool)*nbDrones,false);
    int ind=find_ind_best_order_delivery();
    while(ind!=-1){
        int i=ind;
        //int i=order_best_delivery[m];
        for(int k=0;k<best_delivery[i].size();k++){
            //if(id_warehouse==best_delivery[i][k].first){
                vector<int> id_drones;
                bool redo=true;
                min_dist=999999;id_min=-1;id_warehouse=best_delivery[i][k].first;
                id_drones.clear();
                while(redo){
                    int next_offer=999999;
                    for(int j=0;j<nbDrones;j++){
                        if(drones[j].nextOfferEnd<next_offer)
                            next_offer=drones[j].nextOfferEnd;
                    }
                    int minO=calcul_nextOfferEnd_min();
                    bool used_verif=true;
                    for(int j=0;j<nbDrones;j++){
                        bool verif=true;
                        for(int l=0;l<id_drones.size();l++){
                            if(id_drones[l]==j){
                                verif=false;
                                break;
                            }
                        }
                        int dist=1+search_distance_drone_warehouse(drones[j],best_delivery[i][k].first);
                        if(dist+drones[j].nextOfferEnd<min_dist && verif && drones[j].timeRemaining>=dist+1+calcul_distance_grid(warehouses[best_delivery[i][k].first].coordinates,orders[i].coordinates)&& minO==drones[j].nextOfferEnd){
                            min_dist=dist+drones[j].nextOfferEnd;
                            id_min=j;
                            used_verif=false;
                        }
                    }
                    id_drones.push_back(id_min);
                    if(id_drones.size()*max_weightDrone<typeWeight[best_delivery[i][k].second.first]*best_delivery[i][k].second.second){
                        redo=true;
                    }
                    else
                        redo=false;
                }
                int nb_delivery=best_delivery[i][k].second.second/id_drones.size();
                int rest_delivery=best_delivery[i][k].second.second%id_drones.size();
                for(int l=0;l<id_drones.size();l++){
                    if(l!=id_drones.size()-1 || rest_delivery==0){
                        load_function(&drones[id_drones[l]],&warehouses[best_delivery[i][k].first],best_delivery[i][k].second.first,nb_delivery);
                        deliver_function(&drones[id_drones[l]],&orders[i],best_delivery[i][k].second.first,nb_delivery);
                    }
                    else{
                        load_function(&drones[id_drones[l]],&warehouses[best_delivery[i][k].first],best_delivery[i][k].second.first,rest_delivery);
                        deliver_function(&drones[id_drones[l]],&orders[i],best_delivery[i][k].second.first,rest_delivery);
                    }
                }

                min_dist=999999;id_min=-1;id_warehouse=best_delivery[i][k].first;
                id_drones.clear();


            //}
            /*else{
                id_warehouse=best_delivery[i][k].first;
                min_dist=999999;id_min=0;id_warehouse=best_delivery[i][k].first;
            }*/
        }
        calcul_best_delivery_WO();
        verif_order_done(orders[i]);
        sort_best_delivery_distance_WO();
        ind=find_ind_best_order_delivery();
        //if(verif_all_order_done())
        //            break;
    }
    output << file_output.size() << "\n";
    for(int i=0;i<file_output.size();i++){
        output << file_output[i];
    }

    /**affiche**/

    for(int i=0;i<best_delivery.size();i++){
        cout << "\norder: " << i << "\n";
        cout << "******************\n";
        for(int j=0;j<best_delivery[i].size();j++){
            cout << "warehouse: " << best_delivery[i][j].first;
            cout << " type: " << best_delivery[i][j].second.first;
            cout << " number: " << best_delivery[i][j].second.second;
            cout << "\n";
        }
    }


    input.close();
    output.close();
    return 0;
}

// find closest drone to the warehouse
// then send him to load and deliver
//
