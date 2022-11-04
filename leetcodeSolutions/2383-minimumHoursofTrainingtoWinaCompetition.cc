class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();

        int training = 0;
        for(int i = 0; i < n; ++i) {
            while(initialEnergy <= energy[i] || initialExperience <= experience[i]) {
                int diff = 1 + max(experience[i] - initialExperience, energy[i] - initialEnergy); // +1 to make strictly greater
                training += diff;
                if(energy[i] - initialEnergy > experience[i] - initialExperience) initialEnergy += diff; // making sure we add to correct entity
                else initialExperience += diff;
            }
            initialEnergy -= energy[i], initialExperience += experience[i];
        }

        return training;
    }
};
