using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class AllClientsManager : MonoBehaviour
{
    [SerializeField] GameObject clientObject;
    List<GameObject> allClients;
    bool initialized = false;

    public void onReceiveMessage(string message)
    {
        string[] tokens = message.Split(' ');
        string command = tokens[0];

        if (command == "login")
        {
            if (!initialized)
            {
                initialize(tokens.Skip(2)); //skips the command and the player's own user id
                initialized = true;
            } else
            {
                addPlayer(tokens[1]);
            }
        } else if (command == "logout")
        {
            removePlayer(tokens[1]);
        } else if (command == "move")
        {
            string playerID = tokens[1];
            Vector3 pos = new Vector3(float.Parse(tokens[2]), float.Parse(tokens[3]), float.Parse(tokens[4]));
            Vector3 rot = new Vector3(float.Parse(tokens[5]), float.Parse(tokens[6]), float.Parse(tokens[7]));
            movePlayer(playerID, pos, rot);
        } else if (command == "chat")
        {
            
        } else
        {
            Debug.Log("An error seems to have occurred. Unknown command: " + command);
        }
    }

    private void addPlayer(string playerID)
    {
       
    }

    private void removePlayer(string playerID)
    {

    }

    private void movePlayer(string playerID, Vector3 position, Vector3 rotation)
    {

    }

    private void chatPlayer(string playerID, string sentence)
    {

    }

    private void initialize(IEnumerable<string> clients)
    {
        
    }

}
