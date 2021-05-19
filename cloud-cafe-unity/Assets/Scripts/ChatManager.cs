using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class ChatManager : MonoBehaviour
{
    TMP_Text ChatBox;

    public void updateChatBox(string name, string sentence)
    {
        ChatBox.text = name + ": " + sentence;
    }
}
