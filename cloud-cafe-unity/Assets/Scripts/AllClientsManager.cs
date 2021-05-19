using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class AllClientsManager : MonoBehaviour
{
    [SerializeField] GameObject clientObject;
    [SerializeField] ChatManager chatManager;
    List<OtherPlayer> allClients;
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
            string playerID = tokens[1];
            IEnumerable<string> sentenceTokens = tokens.Skip(2);
            chatPlayer(playerID, string.Join(" ", sentenceTokens.ToArray()));
        } else
        {
            Debug.Log("An error seems to have occurred. Unknown command: " + command);
        }
    }

    private void addPlayer(string playerID)
    {
        OtherPlayer playerToAdd = Instantiate(clientObject, new Vector3(0, 0, 0), Quaternion.identity).GetComponent<OtherPlayer>();
        playerToAdd.playerID = playerID;
        allClients.Add(playerToAdd);
    }

    private void removePlayer(string playerID)
    {
        OtherPlayer playerToRemove = allClients.SingleOrDefault(x => x.playerID == playerID);
        if (playerToRemove != null)
        {
            allClients.Remove(playerToRemove);
            Destroy(playerToRemove.gameObject);
        }
    }

    private void movePlayer(string playerID, Vector3 position, Vector3 rotation)
    {
        OtherPlayer playerToMove = allClients.SingleOrDefault(x => x.playerID == playerID);
        if (playerToMove == null)
        {
            Debug.Log("Error: Received request to move nonexistant player");
        } else
        {
            playerToMove.transform.position = position;
            playerToMove.transform.rotation = Quaternion.Euler(rotation);
        }
    }

    private void chatPlayer(string playerID, string sentence)
    {
        chatManager.updateChatBox(playerID, sentence);
    }

    private void initialize(IEnumerable<string> clients)
    {
        foreach (string client in clients)
        {
            addPlayer(client);
        }
    }

}
