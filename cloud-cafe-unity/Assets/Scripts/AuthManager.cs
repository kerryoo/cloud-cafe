using System;
using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using Michsky.UI.ModernUIPack;
using TMPro;

public class AuthManager : MonoBehaviour
{
    public TMP_InputField usernameInput;
    [SerializeField] Player player;

    private string CouchDBAddress;
    private void Start()
    {
        string CouchDBUsername = Environment.GetEnvironmentVariable("COUCH_DB_USERNAME");
        string CouchDBPassword = Environment.GetEnvironmentVariable("COUCH_DB_PASSWORD");
        string CouchDBIP = Environment.GetEnvironmentVariable("COUCH_DB_IP");

        CouchDBAddress = "http://" + CouchDBUsername + ":" + CouchDBPassword + "@" + CouchDBIP + ":5984/users/";
    }


    public void onLogin()
    {
        StartCoroutine(Login(usernameInput.text));
    }

    IEnumerator Login(string username)
    {
        using (UnityWebRequest webRequest = UnityWebRequest.Head(CouchDBAddress + username))
        {
            // Request and wait for the desired page.
            yield return webRequest.SendWebRequest();

            switch (webRequest.result)
            {
                case UnityWebRequest.Result.ConnectionError:
                case UnityWebRequest.Result.DataProcessingError:
                    Debug.LogError("Error: " + webRequest.error);
                    break;
                case UnityWebRequest.Result.ProtocolError:
                    Debug.LogError("HTTP Error: " + webRequest.error);
                    break;
                case UnityWebRequest.Result.Success:
                    Debug.Log("Received: " + webRequest.downloadHandler.text);
                    player.username = username;
                    player.onLoginSuccess();
                    break;
            }
        }
    }


}
