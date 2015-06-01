class PieceCount{
    int pawnsCount;
     int knightsCount;
       int bishopsCount;
       int rookCount;
       int queensCount;
    
public:
    PieceCount(int pawnsCount, int knightsCount, int bishopsCount, int rookCount, int queensCount){
        this->pawnsCount = pawnsCount;
        this->knightsCount = knightsCount;
        this->bishopsCount = bishopsCount;
        this->rookCount = rookCount;
        this->queensCount = queensCount;
    }
};